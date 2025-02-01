#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

struct SFStringHash
{
    std::size_t operator()(const sf::String &s) const
    {
        return std::hash<std::string>()(s.toAnsiString());
    }
};

class ResourceManager
{
public:
    static ResourceManager &getInstance();
    std::shared_ptr<sf::Texture> getTexture(const sf::String &name);
    void loadTexture(const sf::String &name, const sf::String &path);

private:
    ResourceManager();
    ~ResourceManager();
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    std::unordered_map<sf::String, std::shared_ptr<sf::Texture>, SFStringHash> m_textures;
};

#endif // RESOURCE_MANAGER_HPP