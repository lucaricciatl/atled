
#include "../raylib/src/raylib.h"
#include "Vector3.hpp"
#include <string>
#include <raylib.hpp>


namespace raylib {

namespace{

}  // namespace
raylib::Vector3 raylib::toRaylibVector3(math::Vector3 v) { return {v.GetX(), v.GetY(), v.GetZ()}; }


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

// Draw a model (with texture if set)
void DrawModelSimple(Model model, math::Vector3 position, float scale, Color tint) {
    ::DrawModel(model, raylib::toRaylibVector3(position), scale, tint);
}

// Draw a model with extended parameters
void DrawModelExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, Color tint) {
    ::DrawModelEx(model, raylib::toRaylibVector3(position), raylib::toRaylibVector3(rotationAxis), rotationAngle, raylib::toRaylibVector3(scale), tint);
}

// Draw a model wires (with texture if set)
void DrawModelWiresSimple(Model model, math::Vector3 position, float scale, Color tint) {
    ::DrawModelWires(model, raylib::toRaylibVector3(position), scale, tint);
}

// Draw a model wires (with texture if set) with extended parameters
void DrawModelWiresExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, Color tint) {
    ::DrawModelWiresEx(model, raylib::toRaylibVector3(position), raylib::toRaylibVector3(rotationAxis), rotationAngle, raylib::toRaylibVector3(scale), tint);
}

// Draw a model as points
void DrawModelPointsSimple(Model model, math::Vector3 position, float scale, Color tint) {
    ::DrawModelPoints(model, raylib::toRaylibVector3(position), scale, tint);
}

// Draw a model as points with extended parameters
void DrawModelPointsExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, Color tint) {
    ::DrawModelPointsEx(model, raylib::toRaylibVector3(position), raylib::toRaylibVector3(rotationAxis), rotationAngle, raylib::toRaylibVector3(scale), tint);
}

// Draw bounding box (wires)
void DrawBoundingBoxWires(BoundingBox box, Color color) {
    ::DrawBoundingBox(box, color);
}

// Load shader from files and bind default locations
Shader LoadShader(const char *vsFileName, const char *fsFileName) {
    return ::LoadShader(vsFileName, fsFileName);
}

// Load shader from code strings and bind default locations
Shader LoadShaderFromMemory(const char *vsCode, const char *fsCode) {
    return ::LoadShaderFromMemory(vsCode, fsCode);
}

// Check if a shader is ready
bool IsShaderReady(Shader shader) {
    return ::IsShaderReady(shader);
}
// Draw a billboard texture
void DrawBillboardTexture(Camera camera, Texture2D texture,  math::Vector3 position, float scale, Color tint) {
    ::DrawBillboard(camera, texture, raylib::toRaylibVector3(position), scale, tint);
}

// Draw a billboard texture defined by source
void DrawBillboardTextureRec(Camera camera, Texture2D texture, Rectangle source,  math::Vector3 position, Vector2 size, Color tint) {
    ::DrawBillboardRec(camera, texture, source, raylib::toRaylibVector3(position), size, tint);
}

// Draw a billboard texture defined by source and rotation
void DrawBillboardTexturePro(Camera camera, Texture2D texture, Rectangle source, math::Vector3 position, math::Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint) {
    ::DrawBillboardPro(camera, texture, source, raylib::toRaylibVector3(position), raylib::toRaylibVector3(up), size, origin, rotation, tint);
}

void DrawModel(Model model, ::Vector3 position, float scale, Color tint){
    return ::DrawModel(model, position, scale, tint);               // Draw a model (with texture if set)
};               // Draw a model (with texture if set)

Font GetFontDefault() {
    return ::GetFontDefault();
}
Font LoadFont(const char* fileName) {
    return ::LoadFont(fileName);
}
Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) {
    return ::LoadFontEx(fileName, fontSize, codepoints, codepointCount);
}
Font LoadFontFromImage(Image image, Color key, int firstChar) {
    return ::LoadFontFromImage(image, key, firstChar);
}
Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) {
    return ::LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
}
bool IsFontReady(Font font) {
    return ::IsFontReady(font);
}
GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) {
    return ::LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
}
Image GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) {
    return ::GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod);
}
void UnloadFontData(GlyphInfo* glyphs, int glyphCount) {
    ::UnloadFontData(glyphs, glyphCount);
}
void UnloadFont(Font font) {
    ::UnloadFont(font);
}
bool ExportFontAsCode(Font font, const char* fileName) {
    return ::ExportFontAsCode(font, fileName);
}
void InitWindow(int width, int height, const char* title) {
    ::InitWindow(width, height, title);
}
void CloseWindow() {
    ::CloseWindow();
}
bool WindowShouldClose() {
    return ::WindowShouldClose();
}
bool IsWindowReady() {
    return ::IsWindowReady();
}
bool IsWindowFullscreen() {
    return ::IsWindowFullscreen();
}
bool IsWindowHidden() {
    return ::IsWindowHidden();
}
bool IsWindowMinimized() {
    return ::IsWindowMinimized();
}
bool IsWindowMaximized() {
    return ::IsWindowMaximized();
}
bool IsWindowFocused() {
    return ::IsWindowFocused();
}
bool IsWindowResized() {
    return ::IsWindowResized();
}
bool IsWindowState(unsigned int flag) {
    return ::IsWindowState(flag);
}
void SetWindowState(unsigned int flags) {
    ::SetWindowState(flags);
}
void ClearWindowState(unsigned int flags) {
    ::ClearWindowState(flags);
}
void ToggleFullscreen() {
    ::ToggleFullscreen();
}
void ToggleBorderlessWindowed() {
    ::ToggleBorderlessWindowed();
}
void MaximizeWindow() {
    ::MaximizeWindow();
}
void MinimizeWindow() {
    ::MinimizeWindow();
}
void RestoreWindow() {
    ::RestoreWindow();
}
void SetWindowIcon(Image image) {
    ::SetWindowIcon(image);
}
void SetWindowIcons(Image* images, int count) {
    ::SetWindowIcons(images, count);
}
void SetWindowTitle(const char* title) {
    ::SetWindowTitle(title);
}
void SetWindowPosition(int x, int y) {
    ::SetWindowPosition(x, y);
}
void SetWindowMonitor(int monitor) {
    ::SetWindowMonitor(monitor);
}
void SetWindowMinSize(int width, int height) {
    ::SetWindowMinSize(width, height);
}
void SetWindowMaxSize(int width, int height) {
    ::SetWindowMaxSize(width, height);
}
void SetWindowSize(int width, int height) {
    ::SetWindowSize(width, height);
}
void SetWindowOpacity(float opacity) {
    ::SetWindowOpacity(opacity);
}
void SetWindowFocused() {
    ::SetWindowFocused();
}
void* GetWindowHandle() {
    return ::GetWindowHandle();
}
int GetScreenWidth() {
    return ::GetScreenWidth();
}
int GetScreenHeight() {
    return ::GetScreenHeight();
}
int GetRenderWidth() {
    return ::GetRenderWidth();
}
int GetRenderHeight() {
    return ::GetRenderHeight();
}
int GetMonitorCount() {
    return ::GetMonitorCount();
}
int GetCurrentMonitor() {
    return ::GetCurrentMonitor();
}
Vector2 GetMonitorPosition(int monitor) {
    return ::GetMonitorPosition(monitor);
}
int GetMonitorWidth(int monitor) {
    return ::GetMonitorWidth(monitor);
}
int GetMonitorHeight(int monitor) {
    return ::GetMonitorHeight(monitor);
}
int GetMonitorPhysicalWidth(int monitor) {
    return ::GetMonitorPhysicalWidth(monitor);
}
int GetMonitorPhysicalHeight(int monitor) {
    return ::GetMonitorPhysicalHeight(monitor);
}
int GetMonitorRefreshRate(int monitor) {
    return ::GetMonitorRefreshRate(monitor);
}
Vector2 GetWindowPosition() {
    return ::GetWindowPosition();
}
Vector2 GetWindowScaleDPI() {
    return ::GetWindowScaleDPI();
}
const char* GetMonitorName(int monitor) {
    return ::GetMonitorName(monitor);
}
void SetClipboardText(const char* text) {
    ::SetClipboardText(text);
}
const char* GetClipboardText() {
    return ::GetClipboardText();
}
void DisableEventWaiting() {
    ::DisableEventWaiting();
}
// Gestures and Touch Handling Functions
// Enable a set of gestures using flags
void SetGesturesEnabled(unsigned int flags) {
    ::SetGesturesEnabled(flags);
}
// Check if a gesture has been detected
bool IsGestureDetected(unsigned int gesture) {
    return ::IsGestureDetected(gesture);
}
// Get the latest detected gesture
int GetGestureDetected() {
    return ::GetGestureDetected();
}
// Get gesture hold time in milliseconds
float GetGestureHoldDuration() {
    return ::GetGestureHoldDuration();
}
// Get gesture drag vector
Vector2 GetGestureDragVector() {
    return ::GetGestureDragVector();
}
// Get gesture drag angle
float GetGestureDragAngle() {
    return ::GetGestureDragAngle();
}
// Get gesture pinch delta
Vector2 GetGesturePinchVector() {
    return ::GetGesturePinchVector();
}
// Get gesture pinch angle
float GetGesturePinchAngle() {
    return ::GetGesturePinchAngle();
}
// Check if a mouse button has been pressed once
bool IsMouseButtonPressed(int button) {
    return ::IsMouseButtonPressed(button);
}
// Check if a mouse button is being pressed
bool IsMouseButtonDown(int button) {
    return ::IsMouseButtonDown(button);
}
// Check if a mouse button has been released once
bool IsMouseButtonReleased(int button) {
    return ::IsMouseButtonReleased(button);
}
// Check if a mouse button is NOT being pressed
bool IsMouseButtonUp(int button) {
    return ::IsMouseButtonUp(button);
}
// Get mouse position X
int GetMouseX() {
    return ::GetMouseX();
}
// Get mouse position Y
int GetMouseY() {
    return ::GetMouseY();
}
// Get mouse position XY
Vector2 GetMousePosition() {
    return ::GetMousePosition();
}
// Get mouse delta between frames
Vector2 GetMouseDelta() {
    return ::GetMouseDelta();
}
// Set mouse position XY
void SetMousePosition(int x, int y) {
    ::SetMousePosition(x, y);
}
// Set mouse offset
void SetMouseOffset(int offsetX, int offsetY) {
    ::SetMouseOffset(offsetX, offsetY);
}
// Set mouse scaling
void SetMouseScale(float scaleX, float scaleY) {
    ::SetMouseScale(scaleX, scaleY);
}
// Get mouse wheel movement for X or Y, whichever is larger
float GetMouseWheelMove() {
    return ::GetMouseWheelMove();
}
// Get mouse wheel movement for both X and Y
Vector2 GetMouseWheelMoveV() {
    return ::GetMouseWheelMoveV();
}
// Set mouse cursor
void SetMouseCursor(int cursor) {
    ::SetMouseCursor(cursor);
}
// Touch Input Functions
// Get touch position X for touch point 0 (relative to screen size)
int GetTouchX() {
    return ::GetTouchX();
}
// Get touch position Y for touch point 0 (relative to screen size)
int GetTouchY() {
    return ::GetTouchY();
}
// Get touch position XY for a touch point index (relative to screen size)
Vector2 GetTouchPosition(int index) {
    return ::GetTouchPosition(index);
}
// Get touch point identifier for given index
int GetTouchPointId(int index) {
    return ::GetTouchPointId(index);
}
// Get number of touch points
int GetTouchPointCount() {
    return ::GetTouchPointCount();
}
// Cursor Visibility and Control
// Shows cursor
void ShowCursor() {
    ::ShowCursor();
}
// Hides cursor
void HideCursor() {
    ::HideCursor();
}
// Check if cursor is not visible
bool IsCursorHidden() {
    return ::IsCursorHidden();
}
// Enables cursor (unlock cursor)
void EnableCursor() {
    ::EnableCursor();
}
// Disables cursor (lock cursor)
void DisableCursor() {
    ::DisableCursor();
}
// Check if cursor is on the screen
bool IsCursorOnScreen() {
    return ::IsCursorOnScreen();
}
// Keyboard Input Functions
// Check if a key has been pressed once
bool IsKeyPressed(int key) {
    return ::IsKeyPressed(key);
}
// Check if a key has been pressed again (Only PLATFORM_DESKTOP)
bool IsKeyPressedRepeat(int key) {
    return ::IsKeyPressedRepeat(key);
}
// Check if a key is being pressed
bool IsKeyDown(int key) {
    return ::IsKeyDown(key);
}
// Check if a key has been released once
bool IsKeyReleased(int key) {
    return ::IsKeyReleased(key);
}
// Check if a key is NOT being pressed
bool IsKeyUp(int key) {
    return ::IsKeyUp(key);
}
// Get key pressed (keycode), call it multiple times for keys queued
// Returns 0 when the queue is empty
int GetKeyPressed() {
    return ::GetKeyPressed();
}
// Get char pressed (unicode), call it multiple times for chars queued
// Returns 0 when the queue is empty
int GetCharPressed() {
    return ::GetCharPressed();
}
// Set a custom key to exit program (default is ESC)
void SetExitKey(int key) {
    ::SetExitKey(key);
}
// Gamepad Input Functions
// Check if a gamepad is available
bool IsGamepadAvailable(int gamepad) {
    return ::IsGamepadAvailable(gamepad);
}
// Get gamepad internal name id
const char* GetGamepadName(int gamepad) {
    return ::GetGamepadName(gamepad);
}
// Check if a gamepad button has been pressed once
bool IsGamepadButtonPressed(int gamepad, int button) {
    return ::IsGamepadButtonPressed(gamepad, button);
}
// Check if a gamepad button is being pressed
bool IsGamepadButtonDown(int gamepad, int button) {
    return ::IsGamepadButtonDown(gamepad, button);
}
// Check if a gamepad button has been released once
bool IsGamepadButtonReleased(int gamepad, int button) {
    return ::IsGamepadButtonReleased(gamepad, button);
}
// Check if a gamepad button is NOT being pressed
bool IsGamepadButtonUp(int gamepad, int button) {
    return ::IsGamepadButtonUp(gamepad, button);
}
// Get the last gamepad button pressed
int GetGamepadButtonPressed() {
    return ::GetGamepadButtonPressed();
}
// Get gamepad axis count for a gamepad
int GetGamepadAxisCount(int gamepad) {
    return ::GetGamepadAxisCount(gamepad);
}
// Get axis movement value for a gamepad axis
float GetGamepadAxisMovement(int gamepad, int axis) {
    return ::GetGamepadAxisMovement(gamepad, axis);
}
// Set internal gamepad mappings (SDL_GameControllerDB)
int SetGamepadMappings(const char *mappings) {
    return ::SetGamepadMappings(mappings);
}
// Set gamepad vibration for both motors
void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor) {
    ::SetGamepadVibration(gamepad, leftMotor, rightMotor);
}
// Check collision between two rectangles
bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2) {
    return ::CheckCollisionRecs(rec1, rec2);
}
// Check collision between two circles
bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2) {
    return ::CheckCollisionCircles(center1, radius1, center2, radius2);
}
// Check collision between circle and rectangle
bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec) {
    return ::CheckCollisionCircleRec(center, radius, rec);
}
// Check if point is inside rectangle
bool CheckCollisionPointRec(Vector2 point, Rectangle rec) {
    return ::CheckCollisionPointRec(point, rec);
}
// Check if point is inside circle
bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) {
    return ::CheckCollisionPointCircle(point, center, radius);
}
// Check if point is inside a triangle
bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) {
    return ::CheckCollisionPointTriangle(point, p1, p2, p3);
}
// Check if point is within a polygon described by array of vertices
bool CheckCollisionPointPoly(Vector2 point, const Vector2 *points, int pointCount) {
    return ::CheckCollisionPointPoly(point, points, pointCount);
}
// Check the collision between two lines defined by two points each, returns collision point by reference
bool CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint) {
    return ::CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint);
}
// Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
bool CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold) {
    return ::CheckCollisionPointLine(point, p1, p2, threshold);
}
// Check if circle collides with a line created between two points [p1] and [p2]
bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2) {
    return ::CheckCollisionCircleLine(center, radius, p1, p2);
}
// Get collision rectangle for two rectangles collision
Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2) {
    return ::GetCollisionRec(rec1, rec2);
}
// Draw spline: Linear, minimum 2 points
void DrawSplineLinear(const Vector2 *points, int pointCount, float thick, Color color) {
    ::DrawSplineLinear(points, pointCount, thick, color);
}
// Draw spline: B-Spline, minimum 4 points
void DrawSplineBasis(const Vector2 *points, int pointCount, float thick, Color color) {
    ::DrawSplineBasis(points, pointCount, thick, color);
}
// Draw spline: Catmull-Rom, minimum 4 points
void DrawSplineCatmullRom(const Vector2 *points, int pointCount, float thick, Color color) {
    ::DrawSplineCatmullRom(points, pointCount, thick, color);
}
// Draw spline: Quadratic Bezier, minimum 3 points
void DrawSplineBezierQuadratic(const Vector2 *points, int pointCount, float thick, Color color) {
    ::DrawSplineBezierQuadratic(points, pointCount, thick, color);
}
// Draw spline: Cubic Bezier, minimum 4 points
void DrawSplineBezierCubic(const Vector2 *points, int pointCount, float thick, Color color) {
    ::DrawSplineBezierCubic(points, pointCount, thick, color);
}
// Draw spline segment: Linear, 2 points
void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color) {
    ::DrawSplineSegmentLinear(p1, p2, thick, color);
}
// Draw spline segment: B-Spline, 4 points
void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
    ::DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color);
}
// Draw spline segment: Catmull-Rom, 4 points
void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
    ::DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color);
}
// Draw spline segment: Quadratic Bezier, 2 points, 1 control point
void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color) {
    ::DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color);
}
// Draw spline segment: Cubic Bezier, 2 points, 2 control points
void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color) {
    ::DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color);
}
// Get (evaluate) spline point: Linear
Vector2 GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t) {
    return ::GetSplinePointLinear(startPos, endPos, t);
}
// Get (evaluate) spline point: B-Spline
Vector2 GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
    return ::GetSplinePointBasis(p1, p2, p3, p4, t);
}
// Get (evaluate) spline point: Catmull-Rom
Vector2 GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
    return ::GetSplinePointCatmullRom(p1, p2, p3, p4, t);
}
// Get (evaluate) spline point: Quadratic Bezier
Vector2 GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t) {
    return ::GetSplinePointBezierQuad(p1, c2, p3, t);
}
// Get (evaluate) spline point: Cubic Bezier
Vector2 GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t) {
    return ::GetSplinePointBezierCubic(p1, c2, c3, p4, t);
}
// Draw a color-filled rectangle
void DrawRectangleRec(Rectangle rec, Color color) {
    ::DrawRectangleRec(rec, color);
}
// Draw a color-filled rectangle with pro parameters
void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color) {
    ::DrawRectanglePro(rec, origin, rotation, color);
}
// Draw a vertical-gradient-filled rectangle
void DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom) {
    ::DrawRectangleGradientV(posX, posY, width, height, top, bottom);
}
// Draw a horizontal-gradient-filled rectangle
void DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right) {
    ::DrawRectangleGradientH(posX, posY, width, height, left, right);
}
// Draw a gradient-filled rectangle with custom vertex colors
void DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color topRight, Color bottomRight) {
    ::DrawRectangleGradientEx(rec, topLeft, bottomLeft, topRight, bottomRight);
}
// Draw rectangle outline
void DrawRectangleLines(int posX, int posY, int width, int height, Color color) {
    ::DrawRectangleLines(posX, posY, width, height, color);
}
// Draw rectangle outline with extended parameters
void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color) {
    ::DrawRectangleLinesEx(rec, lineThick, color);
}
// Draw rectangle with rounded edges
void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color) {
    ::DrawRectangleRounded(rec, roundness, segments, color);
}
// Draw rectangle lines with rounded edges
void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color) {
    ::DrawRectangleRoundedLines(rec, roundness, segments, color);
}
// Draw rectangle with rounded edges outline with extended parameters
void DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color) {
    ::DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color);
}
// Draw a color-filled triangle
void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
    ::DrawTriangle(v1, v2, v3, color);
}
// Draw triangle outline
void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
    ::DrawTriangleLines(v1, v2, v3, color);
}
// Draw a triangle fan defined by points
void DrawTriangleFan(const Vector2 *points, int pointCount, Color color) {
    ::DrawTriangleFan(points, pointCount, color);
}
// Draw a triangle strip defined by points
void DrawTriangleStrip(const Vector2 *points, int pointCount, Color color) {
    ::DrawTriangleStrip(points, pointCount, color);
}
// Draw a regular polygon
void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color) {
    ::DrawPoly(center, sides, radius, rotation, color);
}
// Draw a polygon outline
void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color) {
    ::DrawPolyLines(center, sides, radius, rotation, color);
}
// Draw a polygon outline with extended parameters
void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color) {
    ::DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
}
// Set texture and rectangle to be used on shapes drawing
void SetShapesTexture(Texture2D texture, Rectangle source) {
    ::SetShapesTexture(texture, source);
}
// Get texture that is used for shapes drawing
Texture2D GetShapesTexture() {
    return ::GetShapesTexture();
}
// Get texture source rectangle that is used for shapes drawing
Rectangle GetShapesTextureRectangle() {
    return ::GetShapesTextureRectangle();
}
// Draw a pixel
void DrawPixel(int posX, int posY, Color color) {
    ::DrawPixel(posX, posY, color);
}
// Draw a pixel (Vector version)
void DrawPixelV(Vector2 position, Color color) {
    ::DrawPixelV(position, color);
}
// Draw a line
void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
    ::DrawLine(startPosX, startPosY, endPosX, endPosY, color);
}
// Draw a line (using Vector2 positions)
void DrawLineV(Vector2 startPos, Vector2 endPos, Color color) {
    ::DrawLineV(startPos, endPos, color);
}
// Draw a line with thickness
void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color) {
    ::DrawLineEx(startPos, endPos, thick, color);
}
// Draw lines sequence
void DrawLineStrip(const Vector2 *points, int pointCount, Color color) {
    ::DrawLineStrip(points, pointCount, color);
}
// Draw a cubic-bezier line
void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color) {
    ::DrawLineBezier(startPos, endPos, thick, color);
}
// Draw a filled circle
void DrawCircle(int centerX, int centerY, float radius, Color color) {
    ::DrawCircle(centerX, centerY, radius, color);
}
// Draw a sector of a circle
void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
    ::DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
}
// Draw circle sector outline
void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
    ::DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
}
// Draw a gradient-filled circle
void DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer) {
    ::DrawCircleGradient(centerX, centerY, radius, inner, outer);
}
// Draw a filled circle (Vector version)
void DrawCircleV(Vector2 center, float radius, Color color) {
    ::DrawCircleV(center, radius, color);
}
// Draw circle outline
void DrawCircleLines(int centerX, int centerY, float radius, Color color) {
    ::DrawCircleLines(centerX, centerY, radius, color);
}
// Draw circle outline (Vector version)
void DrawCircleLinesV(Vector2 center, float radius, Color color) {
    ::DrawCircleLinesV(center, radius, color);
}
// Draw an ellipse
void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color) {
    ::DrawEllipse(centerX, centerY, radiusH, radiusV, color);
}
// Draw ellipse outline
void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color) {
    ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
}
// Draw a ring
void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
    ::DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}
// Draw ring outline
void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
    ::DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}
// Draw a rectangle
void DrawRectangle(int posX, int posY, int width, int height, Color color) {
    ::DrawRectangle(posX, posY, width, height, color);
}
// Draw a rectangle (Vector version)
void DrawRectangleV(Vector2 position, Vector2 size, Color color) {
    ::DrawRectangleV(position, size, color);
}

// Set background color (framebuffer clear color)
void ClearBackground(Color color) {
    ::ClearBackground(color);
}
// Setup canvas (framebuffer) to start drawing
void BeginDrawing() {
    ::BeginDrawing();
}
// End canvas drawing and swap buffers (double buffering)
void EndDrawing() {
    ::EndDrawing();
}
// Begin 2D mode with custom camera
void BeginMode2D(Camera2D camera) {
    ::BeginMode2D(camera);
}
// Ends 2D mode with custom camera
void EndMode2D() {
    ::EndMode2D();
}
// Begin 3D mode with custom camera
void BeginMode3D(Camera3D camera) {
    ::BeginMode3D(camera);
}
// Ends 3D mode and returns to default 2D orthographic mode
void EndMode3D() {
    ::EndMode3D();
}
// Begin drawing to render texture
void BeginTextureMode(RenderTexture2D target) {
    ::BeginTextureMode(target);
}
// Ends drawing to render texture
void EndTextureMode() {
    ::EndTextureMode();
}
// Begin custom shader drawing
void BeginShaderMode(Shader shader) {
    ::BeginShaderMode(shader);
}
// End custom shader drawing (use default shader)
void EndShaderMode() {
    ::EndShaderMode();
}
// Begin blending mode (alpha, additive, multiplied, subtract, custom)
void BeginBlendMode(int mode) {
    ::BeginBlendMode(mode);
}
// End blending mode (reset to default: alpha blending)
void EndBlendMode() {
    ::EndBlendMode();
}
// Begin scissor mode (define screen area for following drawing)
void BeginScissorMode(int x, int y, int width, int height) {
    ::BeginScissorMode(x, y, width, height);
}
// End scissor mode
void EndScissorMode() {
    ::EndScissorMode();
}
// Begin stereo rendering (requires VR simulator)
void BeginVrStereoMode(VrStereoConfig config) {
    ::BeginVrStereoMode(config);
}
// End stereo rendering (requires VR simulator)
void EndVrStereoMode() {
    ::EndVrStereoMode();
}

// Draw sphere wires
void DrawSphereWires(math::Vector3 centerPos, float radius, int rings, int slices, Color color) {
    ::DrawSphereWires(raylib::toRaylibVector3(centerPos), radius, rings, slices, color);
}
// Draw a cylinder/cone
void DrawCylinder(math::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    ::DrawCylinder(raylib::toRaylibVector3(position), radiusTop, radiusBottom, height, slices, color);
}
// Draw a cylinder with base at startPos and top at endPos
void DrawCylinderEx(math::Vector3 startPos, math::Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    ::DrawCylinderEx(raylib::toRaylibVector3(startPos), raylib::toRaylibVector3(endPos), startRadius, endRadius, sides, color);
}
// Draw cylinder/cone wires
void DrawCylinderWires(math::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    ::DrawCylinderWires(raylib::toRaylibVector3(position), radiusTop, radiusBottom, height, slices, color);
}
// Draw cylinder wires with base at startPos and top at endPos
void DrawCylinderWiresEx(math::Vector3 startPos, math::Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    ::DrawCylinderWiresEx(raylib::toRaylibVector3(startPos), raylib::toRaylibVector3(endPos), startRadius, endRadius, sides, color);
}
// Draw a capsule with the center of its sphere caps at startPos and endPos
void DrawCapsule(math::Vector3 startPos, math::Vector3 endPos, float radius, int slices, int rings, Color color) {
    ::DrawCapsule(raylib::toRaylibVector3(startPos), raylib::toRaylibVector3(endPos), radius, slices, rings, color);
}
// Draw capsule wireframe with the center of its sphere caps at startPos and endPos
void DrawCapsuleWires(math::Vector3 startPos, math::Vector3 endPos, float radius, int slices, int rings, Color color) {
    ::DrawCapsuleWires(raylib::toRaylibVector3(startPos), raylib::toRaylibVector3(endPos), radius, slices, rings, color);
}
// Draw a plane on the XZ axis
void DrawPlane(math::Vector3 centerPos, Vector2 size, Color color) {
    ::DrawPlane(raylib::toRaylibVector3(centerPos), size, color);
}
// Draw a ray line
void DrawRay(Ray ray, Color color) {
    ::DrawRay(ray, color);
}
// Draw a grid (centered at (0, 0, 0))
void DrawGrid(int slices, float spacing) {
    ::DrawGrid(slices, spacing);
}
// Takes a screenshot of current screen (filename extension defines format)
void TakeScreenshot(const char *fileName) {
    ::TakeScreenshot(fileName);
}
// Setup init configuration flags (view FLAGS)
void SetConfigFlags(unsigned int flags) {
    ::SetConfigFlags(flags);
}
// Open URL with default system browser (if available)
void OpenURL(const char *url) {
    ::OpenURL(url);
}
// Draw a line in 3D world space
void DrawLine3D(math::Vector3 startPos, math::Vector3 endPos, Color color) {
    ::DrawLine3D(raylib::toRaylibVector3(startPos), raylib::toRaylibVector3(endPos), color);
}
// Draw a point in 3D space, actually a small line
void DrawPoint3D(math::Vector3 position, Color color) {
    ::DrawPoint3D(raylib::toRaylibVector3(position), color);
}
// Draw a circle in 3D world space
void DrawCircle3D(math::Vector3 center, float radius, math::Vector3 rotationAxis, float rotationAngle, Color color) {
    ::DrawCircle3D(raylib::toRaylibVector3(center), radius, raylib::toRaylibVector3(rotationAxis), rotationAngle, color);
}
// Draw a color-filled triangle (vertex in counter-clockwise order!)
void DrawTriangle3D(math::Vector3 v1, math::Vector3 v2, math::Vector3 v3, Color color) {
    ::DrawTriangle3D(raylib::toRaylibVector3(v1), raylib::toRaylibVector3(v2), raylib::toRaylibVector3(v3), color);
}
// Draw a triangle strip defined by points
void DrawTriangleStrip3D(const Vector3 *points, int pointCount, Color color) {
    ::DrawTriangleStrip3D(points, pointCount, color);
}
// Draw a cube
void DrawCube(math::Vector3 position, float width, float height, float length, Color color) {
    ::DrawCube(raylib::toRaylibVector3(position), width, height, length, color);
}
// Draw cube (Vector version)
void DrawCubeV(math::Vector3 position, math::Vector3 size, Color color) {
    ::DrawCubeV(raylib::toRaylibVector3(position), raylib::toRaylibVector3(size), color);
}
// Draw cube wires
void DrawCubeWires(math::Vector3 position, float width, float height, float length, Color color) {
    ::DrawCubeWires(raylib::toRaylibVector3(position), width, height, length, color);
}
// Draw cube wires (Vector version)
void DrawCubeWiresV(math::Vector3 position, math::Vector3 size, Color color) {
    ::DrawCubeWiresV(raylib::toRaylibVector3(position), raylib::toRaylibVector3(size), color);
}
// Draw sphere
void DrawSphere(math::Vector3 centerPos, float radius, Color color) {
    ::DrawSphere(raylib::toRaylibVector3(centerPos), radius, color);
}
// Draw sphere with extended parameters
void DrawSphereEx(math::Vector3 centerPos, float radius, int rings, int slices, Color color) {
    ::DrawSphereEx(raylib::toRaylibVector3(centerPos), radius, rings, slices, color);
}
void DrawFPS(int posX, int posY) {
    ::DrawFPS(posX, posY);
}
void DrawText(const char* text, int posX, int posY, int fontSize, Color color) {
    ::DrawText(text, posX, posY, fontSize, color);
}
void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint) {
    ::DrawTextEx(font, text, position, fontSize, spacing, tint);
}
void DrawTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
    ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);
}
void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
    ::DrawTextCodepoint(font, codepoint, position, fontSize, tint);
}
void DrawTextCodepoints(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint) {
    ::DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint);
}
void UpdateCamera(Camera *camera, int mode){::UpdateCamera(camera, mode);};      // Update camera position for selected mode

void EnableEventWaiting(void){::EnableEventWaiting();};                              // Enable waiting for events on EndDrawing(), no automatic event polling
Model LoadModel(const std::string& path) {
    return ::LoadModel(path.c_str());
}
// Mesh generation function wrappers

Model LoadModelFromMesh(Mesh mesh){
    return ::LoadModelFromMesh(mesh);
    };

// Generate polygonal mesh
Mesh GenMeshPoly(int sides, float radius) {
    return ::GenMeshPoly(sides, radius);
}

// Generate plane mesh (with subdivisions)
Mesh GenMeshPlane(float width, float length, int resX, int resZ) {
    return ::GenMeshPlane(width, length, resX, resZ);
}

// Generate cuboid mesh
Mesh GenMeshCube(float width, float height, float length) {
    return ::GenMeshCube(width, height, length);
}

// Generate sphere mesh
Mesh GenMeshSphere(float radius, int rings, int slices) {
    return ::GenMeshSphere(radius, rings, slices);
}

// Generate half-sphere mesh
Mesh GenMeshHemiSphere(float radius, int rings, int slices) {
    return ::GenMeshHemiSphere(radius, rings, slices);
}

// Generate cylinder mesh
Mesh GenMeshCylinder(float radius, float height, int slices) {
    return ::GenMeshCylinder(radius, height, slices);
}

// Generate cone/pyramid mesh
Mesh GenMeshCone(float radius, float height, int slices) {
    return ::GenMeshCone(radius, height, slices);
}

// Generate torus mesh
Mesh GenMeshTorus(float radius, float size, int radSeg, int sides) {
    return ::GenMeshTorus(radius, size, radSeg, sides);
}

// Generate trefoil knot mesh
Mesh GenMeshKnot(float radius, float size, int radSeg, int sides) {
    return ::GenMeshKnot(radius, size, radSeg, sides);
}

// Generate heightmap mesh from image data
Mesh GenMeshHeightmap(Image heightmap, Vector3 size) {
    return ::GenMeshHeightmap(heightmap, size);
}

// Generate cubes-based map mesh from image data
Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize) {
    return ::GenMeshCubicmap(cubicmap, cubeSize);
}

void UpdateLightValues(raylib::Shader shader, Light light) {
    UpdateLightValues(shader,light);
}


Light CreateLight(int type, math::Vector3 position, math::Vector3 target, ::Color color,
                                ::Shader shader) {
    auto raypos = toRaylibVector3(position);
    auto raypos2 = toRaylibVector3(target);
    Light light = { 0 };

    light.enabled = true;
    light.type = type;
    light.position = raypos;
    light.target = raypos2;
    light.color = color;

    // NOTE: Lighting shader naming must be the provided ones
    light.enabledLoc = GetShaderLocation(shader, TextFormat("lights.enabled"));
    light.typeLoc = GetShaderLocation(shader, TextFormat("lights.type"));
    light.positionLoc = GetShaderLocation(shader, TextFormat("lights.position"));
    light.targetLoc = GetShaderLocation(shader, TextFormat("lights.target"));
    light.colorLoc = GetShaderLocation(shader, TextFormat("lights.color"));

    UpdateLightValues(shader, light);
        

    return light;
}


} // namespace raylib

