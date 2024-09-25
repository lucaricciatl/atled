#include "raylib.h"

namespace camera {

typedef struct ::Camera3D Camera3D;

typedef ::Camera3D Camera;    // Camera type fallback, defaults to Camera3D

// Camera2D, defines position/orientation in 2d space
typedef struct ::Camera2D Camera2D;

}