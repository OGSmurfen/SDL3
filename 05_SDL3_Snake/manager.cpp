#include "manager.h"

/// <summary>
/// Checks if r1 collides with r1
/// </summary>
/// <param name="r1"></param>
/// <param name="r2"></param>
/// <returns>true if there is a collision and false if not</returns>
bool PapaSmurfie::CheckCollision(const SDL_FRect& r1, const SDL_FRect& r2)
{
    if (r1.x + r1.w > r2.x && r1.x < r2.x + r2.w)
    {
        if(r1.y + r1.h > r2.y && r1.y < r2.y + r2.h)
            return true;
    }
    return false;
}
