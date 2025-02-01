
#include "ResourceManager/ResourceManager.hpp"

ResourceManager &ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const sf::String &name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end())
    {
        return it->second;
    }
    return nullptr;
}

void ResourceManager::loadTexture(const sf::String &name, const sf::String &path)
{
    auto texture = std::make_shared<sf::Texture>();
    if (texture->loadFromFile(path))
    {
        m_textures.insert({name, texture});
    }
}
