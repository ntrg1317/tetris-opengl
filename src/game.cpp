#include <ctime>
#include <sstream>
#include <string>

#include "game.h"
#include "resourceManager.h"
#include "render.h"
#include "squareMap.h"
#include "block.h"

// Game-related State data
Render* Renderer;
SquareMap* Squares;
Tetromino* CurrBlock;
Tetromino* NextBlock;
Block *Block;

int score = 0;
blockType random_type_next = static_cast<blockType>(rand() % T);
std::string name_next = Block->getName(random_type_next).second;
bool endGame = false;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height) { }

Game::~Game()
{
    delete Renderer;
    delete Squares;
    delete Block;
    delete NextBlock;
    delete CurrBlock;
}

void Game::Init()
{
    this->gameSpeed = 2.5f;

    // load shaders
    ResourceManager::LoadShader((std::string(ASSET_PATH) + "/shaders/spriteVs.glsl").c_str(), (std::string(ASSET_PATH) + "/shaders/spriteFs.glsl").c_str(), "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader spriteShader = ResourceManager::GetShader("sprite");
    Renderer = new class Render(spriteShader);
    // load textures
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/8.png").c_str(), true, "square");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/7.png").c_str(), true, "block");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/1.png").c_str(), true, "I");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/2.png").c_str(), true, "J");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/3.png").c_str(), true, "L");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/4.png").c_str(), true, "O");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/5.png").c_str(), true, "S");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/6.png").c_str(), true, "T");
    ResourceManager::LoadTexture((std::string(ASSET_PATH) + "/textures/7.png").c_str(), true, "Z");

    srand(std::time(NULL));
    Squares = new SquareMap(glm::vec2(0.0f, 0.0f), glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture("square"), glm::vec3(1.0f, 1.0f, 1.0f));
    blockType random_type = static_cast<blockType>(rand() % T);
    std::string name =  Block->getName(random_type).second;
    CurrBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(name), 3, 1, random_type, glm::vec3(1.0f, 1.0f, 0.0f));
    blockType next_random_type = static_cast<blockType>(rand() % T);
    std::string next_name =  Block->getName(next_random_type).second;
    NextBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(next_name), 12, 3, next_random_type, glm::vec3(1.0f, 1.0f, 0.0f));
}

void Game::Update()
{

    if (endGame) {
        return;
    }
    if (CurrBlock->checkDownAvail(Squares->getValues())) {
        CurrBlock->downUpdate();
    } else {
        std::cout << "BLOCK COLLAPSE SIGNAL INSIDE GAME" << std::endl;
        Squares->collapseBlock(CurrBlock->getCollapseVals());
        Squares->checkLines(score);

        CurrBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(name_next), 3, 1, random_type_next, glm::vec3(1.0f, 1.0f, 0.0f));
        CurrBlock->checkFinish(Squares->getValues(), endGame);
        if (endGame) {
            std::cout << "Game has ended" << std::endl;
            this->State = GAME_END;
            return;
        }
        this->gameSpeed = 2.5f - (score / 10) * 0.02;
        random_type_next = static_cast<blockType>(rand() % T);
        name_next = Block->getName(random_type_next).second;
        NextBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(name_next), 12, 3, random_type_next, glm::vec3(1.0f, 1.0f, 0.0f));
        std::cout << "Score: " << score << std::endl;
    }
}

float Game::getTimeUpdate() {
    return this->gameSpeed;
}
void Game::ProcessInput()
{
    if (this->State == GAME_ACTIVE) {
        if (CurrBlock->Alive) {
            if (this->Keys[GLFW_KEY_UP]) {
                if (checkBoundariesRotation()) {
                    CurrBlock->changeRotation();
                }
            }
            if (this->Keys[GLFW_KEY_RIGHT]) {
                if (checkBoundariesMovement(Right_movement)) {
                    CurrBlock->changePosRight();
                }
            }
            if (this->Keys[GLFW_KEY_LEFT]) {
                if (checkBoundariesMovement(Left_movement)) {
                    CurrBlock->changePosLeft();
                }
            }
        }
    }
    if (this->State == GAME_END) {
        std::string score_str = std::to_string(score);
    }
}
void Game::resetGame() {
    Squares->resetVals();
    score = 0;
    resetBlocks();
    this->State = GAME_ACTIVE;
    endGame = false;
    this->gameSpeed = 2.5f;
}
void Game::resetBlocks() {
    blockType random_type = static_cast<blockType>(rand() % T);
    std::string name = Block->getName(random_type).second;
    CurrBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(name), 3, 1, random_type, glm::vec3(1.0f, 1.0f, 0.0f));
    random_type_next = static_cast<blockType>(rand() % T);
    name_next = Block->getName(random_type_next).second;
    NextBlock = new Tetromino(glm::vec2(0.0f, 0.0f), true, Up_rotation, glm::vec2(40.0f, 40.0f), ResourceManager::GetTexture(name_next), 12, 3, random_type_next, glm::vec3(1.0f, 1.0f, 0.0f));
}
bool Game::checkBoundariesRotation() {
    bool availability = CurrBlock->checkRotationAvail(Squares->getValues());
    return availability;
}
bool Game::checkBoundariesMovement(movementType moveType) {
    bool availability = CurrBlock->checkMovementAvail(Squares->getValues(), moveType);
    return availability;

}
void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        // draw background
        // Texture background_Texture = ResourceManager::GetTexture("background");
        // Renderer->DrawSprite(background_Texture, glm::vec2(0.0f, .0f), glm::vec2(this->Width, this->Height), 0.0f);

        //Draw Objects
        Squares->Draw(*Renderer);
        CurrBlock->Draw(*Renderer);
        NextBlock->Draw(*Renderer);

        std::string score_str = std::to_string(score);

    }
    if (this->State == GAME_END) {
        std::string score_str = std::to_string(score);
        std::cout << score_str;
    }
}