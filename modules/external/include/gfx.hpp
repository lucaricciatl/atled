#include "raylib.h"
#include "types.hpp"

namespace gfx{

typedef ::ConfigFlags ConfigFlags;

typedef ::Color Color;  // Using the fully qualified type from raylib

// Some Basic Colors
// NOTE: Custom raylib color palette for amazing visuals on WHITE background
#define GFX_LIGHTGRAY  { 200, 200, 200, 255 }   // Light Gray
#define GFX_GRAY       { 130, 130, 130, 255 }   // Gray
#define GFX_DARKGRAY   { 80, 80, 80, 255 }      // Dark Gray
#define GFX_YELLOW     { 253, 249, 0, 255 }     // Yellow
#define GFX_GOLD       { 255, 203, 0, 255 }     // Gold
#define GFX_ORANGE     { 255, 161, 0, 255 }     // Orange
#define GFX_PINK       { 255, 109, 194, 255 }   // Pink
#define GFX_RED        { 230, 41, 55, 255 }     // Red
#define GFX_MAROON     { 190, 33, 55, 255 }     // Maroon
#define GFX_GREEN      { 0, 228, 48, 255 }      // Green
#define GFX_LIME       { 0, 158, 47, 255 }      // Lime
#define GFX_DARKGREEN  { 0, 117, 44, 255 }      // Dark Green
#define GFX_SKYBLUE    { 102, 191, 255, 255 }   // Sky Blue
#define GFX_BLUE       { 0, 121, 241, 255 }     // Blue
#define GFX_DARKBLUE   { 0, 82, 172, 255 }      // Dark Blue
#define GFX_PURPLE     { 200, 122, 255, 255 }   // Purple
#define GFX_VIOLET     { 135, 60, 190, 255 }    // Violet
#define GFX_DARKPURPLE { 112, 31, 126, 255 }    // Dark Purple
#define GFX_BEIGE      { 211, 176, 131, 255 }   // Beige
#define GFX_BROWN      { 127, 106, 79, 255 }    // Brown
#define GFX_DARKBROWN  { 76, 63, 47, 255 }      // Dark Brown

#define GFX_WHITE      { 255, 255, 255, 255 }   // White
#define GFX_BLACK      { 0, 0, 0, 255 }         // Black
#define GFX_BLANK      { 0, 0, 0, 0 }           // Blank (Transparent)
#define GFX_MAGENTA    { 255, 0, 255, 255 }     // Magenta
#define GFX_RAYWHITE   { 245, 245, 245, 255 }   // My own White

int GetScreenWidth(void);                                   // Get current screen width
int GetScreenHeight(void);                                  // Get current screen height
int GetRenderWidth(void);                                   // Get current render width (it considers HiDPI)
int GetRenderHeight(void);                                  // Get current render height (it considers HiDPI)
int GetMonitorCount(void);                                  // Get number of connected monitors
int GetCurrentMonitor(void);                                // Get current connected monitor
Vector2 GetMonitorPosition(int monitor);                    // Get specified monitor position
int GetMonitorWidth(int monitor);                           // Get specified monitor width (current video mode used by monitor)
int GetMonitorHeight(int monitor);                          // Get specified monitor height (current video mode used by monitor)
int GetMonitorPhysicalWidth(int monitor);                   // Get specified monitor physical width in millimetres
int GetMonitorPhysicalHeight(int monitor);                  // Get specified monitor physical height in millimetres
int GetMonitorRefreshRate(int monitor);                     // Get specified monitor refresh rate
Vector2 GetWindowPosition(void);                            // Get window position XY on monitor
Vector2 GetWindowScaleDPI(void);                            // Get window scale DPI factor
const char *GetMonitorName(int monitor);                    // Get the human-readable, UTF-8 encoded name of the specified monitor
void SetClipboardText(const char *text);                    // Set clipboard text content
const char *GetClipboardText(void);                         // Get clipboard text content
void EnableEventWaiting(void);                              // Enable waiting for events on EndDrawing(), no automatic event polling
void DisableEventWaiting(void);                             // Disable waiting for events on EndDrawing(), automatic events polling

// Misc. functions
void TakeScreenshot(const char *fileName);                  // Takes a screenshot of current screen (filename extension defines format)
void SetConfigFlags(unsigned int flags);                    // Setup init configuration flags (view FLAGS)
void OpenURL(const char *url);                              // Open URL with default system browser (if available)

// Basic geometric 3D shapes drawing functions
void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);                                    // Draw a line in 3D world space
void DrawPoint3D(Vector3 position, Color color);                                                   // Draw a point in 3D space, actually a small line
void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color); // Draw a circle in 3D world space
void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);                              // Draw a color-filled triangle (vertex in counter-clockwise order!)
void DrawTriangleStrip3D(const Vector3 *points, int pointCount, Color color);                      // Draw a triangle strip defined by points
void DrawCube(Vector3 position, float width, float height, float length, Color color);             // Draw cube
void DrawCubeV(Vector3 position, Vector3 size, Color color);                                       // Draw cube (Vector version)
void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);        // Draw cube wires
void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);                                  // Draw cube wires (Vector version)
void DrawSphere(Vector3 centerPos, float radius, Color color);                                     // Draw sphere
void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);            // Draw sphere with extended parameters
void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);         // Draw sphere wires
void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone
void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color); // Draw a cylinder with base at startPos and top at endPos
void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone wires
void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color); // Draw a cylinder wires with base at startPos and top at endPos
void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color); // Draw a capsule with the center of its sphere caps at startPos and endPos
void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color); // Draw capsule wireframe with the center of its sphere caps at startPos and endPos
void DrawPlane(Vector3 centerPos, Vector2 size, Color color);                                      // Draw a plane XZ
void DrawRay(Ray ray, Color color);                                                                // Draw a ray line
void DrawGrid(int slices, float spacing);                                                          // Draw a grid (centered at (0, 0, 0))

// Drawing-related functions
void ClearBackground(Color color);                          // Set background color (framebuffer clear color)
void BeginDrawing(void);                                    // Setup canvas (framebuffer) to start drawing
void EndDrawing(void);                                      // End canvas drawing and swap buffers (double buffering)
void BeginMode2D(Camera2D camera);                          // Begin 2D mode with custom camera (2D)
void EndMode2D(void);                                       // Ends 2D mode with custom camera
void BeginMode3D(Camera3D camera);                          // Begin 3D mode with custom camera (3D)
void EndMode3D(void);                                       // Ends 3D mode and returns to default 2D orthographic mode
void BeginTextureMode(RenderTexture2D target);              // Begin drawing to render texture
void EndTextureMode(void);                                  // Ends drawing to render texture
void BeginShaderMode(Shader shader);                        // Begin custom shader drawing
void EndShaderMode(void);                                   // End custom shader drawing (use default shader)
void BeginBlendMode(int mode);                              // Begin blending mode (alpha, additive, multiplied, subtract, custom)
void EndBlendMode(void);                                    // End blending mode (reset to default: alpha blending)
void BeginScissorMode(int x, int y, int width, int height); // Begin scissor mode (define screen area for following drawing)
void EndScissorMode(void);                                  // End scissor mode
void BeginVrStereoMode(VrStereoConfig config);              // Begin stereo rendering (requires VR simulator)
void EndVrStereoMode(void);                                 // End stereo rendering (requires VR simulator)
//------------------------------------------------------------------------------------
// Functions Declaration - Vertex level operations
//------------------------------------------------------------------------------------
void rlBegin(int mode);                           // Initialize drawing mode (how to organize vertex)
void rlEnd(void);                                 // Finish vertex providing
void rlVertex2i(int x, int y);                    // Define one vertex (position) - 2 int
void rlVertex2f(float x, float y);                // Define one vertex (position) - 2 float
void rlVertex3f(float x, float y, float z);       // Define one vertex (position) - 3 float
void rlTexCoord2f(float x, float y);              // Define one vertex (texture coordinate) - 2 float
void rlNormal3f(float x, float y, float z);       // Define one vertex (normal) - 3 float
void rlColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a); // Define one vertex (color) - 4 byte
void rlColor3f(float x, float y, float z);        // Define one vertex (color) - 3 float
void rlColor4f(float x, float y, float z, float w); // Define one vertex (color) - 4 float

}