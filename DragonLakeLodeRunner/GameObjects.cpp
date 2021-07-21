#include "GameObjects.h"
#include "Camera.h"

int GameObjects::tileSize = 32;

Vector2 GameObjects::GetOffsetPosition(int index)
{
    if (!HaveIndex(index))
        return Vector2(-1, -1);
    Vector2 offset = camera->GetOffset();
    return positions[index] + offset;
}

bool GameObjects::HaveIndex(int index)
{
    return index >= 0 && index < positions.size();
}

void GameObjects::RemoveAt(int index)
{
    positions.erase(positions.begin()+index);
    sizes.erase(sizes.begin() + index);
    velocities.erase(velocities.begin() + index);
    types.erase(types.begin() + index);
    states.erase(states.begin() + index);
    
    destroySprite(sprites[index]);
    sprites.erase(sprites.begin() + index);
}

void GameObjects::RemoveGameObjects()
{
    int c = needToRemove.size();
    while (c > 0)
    {
        for (int i = needToRemove.size() - 1; i >= 0; i--)
        {
            c = i;
            if (needToRemove[i])
            {
                RemoveAt(needToRemove[i]);
                break;
            }
        }
    }

    needToRemove.clear();
}

GameObjects::GameObjects()
{
    positions = vector<Vector2>();
    sizes = vector<Vector2Int>();
    sprites = vector<Sprite*>();
    types = vector<GameObjectType>();
    velocities = vector<Vector2>();

    camera = new Camera();
    spawners = std::make_unique<Spawners>(this);
    collisions = std::make_unique<Collisions>(this);
    controllers = std::make_unique<Controllers>(this);

    needToRemove = vector<int>();

    camera->Init();
}

void GameObjects::Update(float deltaTime)
{
    for (int i = 0; i < positions.size(); i++)
    {
        if (types[i] == GameObjectType::Hero)
        {
            camera->SetLockPosition(positions[i]);
        }
        if (types[i] == GameObjectType::Hero || types[i] == GameObjectType::Enemy)
        {
            if (velocities[i].y > 0)
            {
                velocities[i].x = 0;
            }
        }
        Vector2 velocity = Vector2(velocities[i].x * deltaTime, velocities[i].y * deltaTime);
        positions[i] = positions[i] + velocity;
       
        //fall
        if (types[i] == GameObjectType::Hero || types[i] == GameObjectType::Enemy)
        {
            if (states[i] == GameObjectState::Ladder)
                states[i] = GameObjectState::Fall;
            else
            {
                velocities[i].y = 30;
            }
        }
        
    }
    collisions->Process(deltaTime);
    controllers->Process(deltaTime);
    spawners->Process(deltaTime);
    RemoveGameObjects();
}

void GameObjects::Draw()
{
    for (int i = 0; i < sprites.size(); i++)
    {
        Vector2 offset = GetOffsetPosition(i);
        drawSprite(sprites[i], offset.x, offset.y);
    }
}

void GameObjects::AddGameObject(Vector2 position, Sprite* sprite, GameObjectType type, GameObjectState state, Vector2Int size, Vector2 velocity)
{
    positions.push_back(position);
    sizes.push_back(size);
    velocities.push_back(velocity);
    sprites.push_back(sprite);
    states.push_back(state);
    types.push_back(type);
}

Vector2 GameObjects::GetPositionByIndex(int index)
{
    if (HaveIndex(index))
        return positions[index];
    return Vector2(0,0);
}

Vector2Int GameObjects::GetSizeByIndex(int index)
{
    if (HaveIndex(index))
    {
        return sizes[index];
    }
    return Vector2Int(tileSize, tileSize);
}

GameObjectType GameObjects::GetTypeByIndex(int index)
{
    if (HaveIndex(index))
        return types[index];
    return GameObjectType::Obstacle;
}

Vector2 GameObjects::GetVelocityByIndex(int index)
{
    if (HaveIndex(index))
        return velocities[index];

    return Vector2(0,0);
}

GameObjectState GameObjects::GetStateByIndex(int index)
{
    if (HaveIndex(index))
        return states[index];
    return GameObjectState::Idle;
}

bool GameObjects::NeedToRemove(int index)
{
    for (int i = 0; i < needToRemove.size(); i++)
        if (needToRemove[i] == index) return true;
    
    return false;
}

void GameObjects::SetPosition(int index, Vector2 position)
{
    if (HaveIndex(index))
        positions[index] = position;
}

void GameObjects::SetVelocity(int index, Vector2 velocity)
{
    if (HaveIndex(index))
    {
        velocities[index] = velocity;
    }
}

void GameObjects::SetSprite(int index, Sprite* sprite)
{
    if (HaveIndex(index))
    {
        destroySprite(sprites[index]);
        sprites[index] = sprite;
    }
}

void GameObjects::SetState(int index, GameObjectState state)
{
    if (HaveIndex(index))
        states[index] = state;
}

int GameObjects::GetObjectNumber()
{
    return positions.size();
}

int GameObjects::GetIndexByPosition(Vector2 position)
{
    for (int i = 0; i < positions.size(); i++)
    {
        if (position.x >= positions[i].x &&
            position.x <= positions[i].x + sizes[i].x &&
            position.y >= positions[i].y &&
            position.y <= positions[i].y + sizes[i].y) 
            return i;
    }
    return -1;
}

int GameObjects::GetFirstIndexByType(GameObjectType type)
{
    for (int i = 0; i < types.size(); i++)
    {
        if (types[i] == type) return i;
    }
    return -1;
}

vector<int> GameObjects::GetIndexesByType(GameObjectType type)
{
    vector<int> indexes = vector<int>();
    for (int i = 0; i < types.size(); i++)
    {
        if (types[i] == type) indexes.push_back(i);
    }
    return indexes;
}

void GameObjects::onMouseMove(int x, int y, int xrelative, int yrelative)
{
    controllers->onMouseMove(x, y, xrelative, yrelative);
}

void GameObjects::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
    controllers->onMouseButtonClick(button, isReleased);
}

void GameObjects::onKeyPressed(FRKey k)
{
    controllers->onKeyPressed(k);
}

void GameObjects::onKeyReleased(FRKey k)
{
    controllers->onKeyReleased(k);
}

void GameObjects::RemoveAtIndex(int index)
{
    if (HaveIndex(index))
        needToRemove.push_back(index);
}

void GameObjects::RemoveAtPosition(Vector2 position)
{
    int index = GetIndexByPosition(position);
    if (HaveIndex(index))
        needToRemove.push_back(index);
}
