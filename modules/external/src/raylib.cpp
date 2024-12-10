
#include "../raylib/src/raylib.h"
#include "Vector3.hpp"
#include <string>
#include "Color.hpp"

namespace raylib {
    Vector3 toRaylibVector3(math::Vector3 v){return {v.getX(),v.getY(),v.getZ()};}
    Color toRaylibColor(const graphics::Color& c) {
    return { 
        static_cast<unsigned char>(c.getRed() * 255),
        static_cast<unsigned char>(c.getGreen() * 255),
        static_cast<unsigned char>(c.getBlue() * 255),
        static_cast<unsigned char>(c.getAlpha() * 255)
    };
}

void DrawModel(Model model, math::Vector3 position, float scale, graphics::Color tint){
    return ::DrawModel(model, toRaylibVector3(position), scale, toRaylibColor(tint));               // Draw a model (with texture if set)
};               

// Draw a model (with texture if set)
void DrawModelSimple(Model model, math::Vector3 position, float scale, graphics::Color tint) {
    ::DrawModel(model, toRaylibVector3(position), scale, toRaylibColor(tint));
}

// Draw a model with extended parameters
void DrawModelExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphics::Color tint) {
    ::DrawModelEx(model, toRaylibVector3(position), toRaylibVector3(rotationAxis), rotationAngle, toRaylibVector3(scale), toRaylibColor(tint));
}

// Draw a model wires (with texture if set)
void DrawModelWiresSimple(Model model, math::Vector3 position, float scale, graphics::Color tint) {
    ::DrawModelWires(model, toRaylibVector3(position), scale, toRaylibColor(tint));
}

// Draw a model wires (with texture if set) with extended parameters
void DrawModelWiresExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphics::Color tint) {
    ::DrawModelWiresEx(model, toRaylibVector3(position), toRaylibVector3(rotationAxis), rotationAngle, toRaylibVector3(scale), toRaylibColor(tint));
}

// Draw a model as points
void DrawModelPointsSimple(Model model, math::Vector3 position, float scale, graphics::Color tint) {
    ::DrawModelPoints(model, toRaylibVector3(position), scale, toRaylibColor(tint));
}

// Draw a model as points with extended parameters
void DrawModelPointsExtended(Model model, math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphics::Color tint) {
    ::DrawModelPointsEx(model, toRaylibVector3(position), toRaylibVector3(rotationAxis), rotationAngle, toRaylibVector3(scale), toRaylibColor(tint));
}

// Draw bounding box (wires)
void DrawBoundingBoxWires(BoundingBox box, graphics::Color color) {
    ::DrawBoundingBox(box, toRaylibColor(color));
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
void DrawBillboardTexture(Camera camera, Texture2D texture,  math::Vector3 position, float scale, graphics::Color tint) {
    ::DrawBillboard(camera, texture, toRaylibVector3(position), scale, toRaylibColor(tint));
}

// Draw a billboard texture defined by source
void DrawBillboardTextureRec(Camera camera, Texture2D texture, Rectangle source,  math::Vector3 position, Vector2 size, graphics::Color tint) {
    ::DrawBillboardRec(camera, texture, source, toRaylibVector3(position), size, toRaylibColor(tint));
}

// Draw a billboard texture defined by source and rotation
void DrawBillboardTexturePro(Camera camera, Texture2D texture, Rectangle source, math::Vector3 position, math::Vector3 up, Vector2 size, Vector2 origin, float rotation, graphics::Color tint) {
    ::DrawBillboardPro(camera, texture, source, toRaylibVector3(position), toRaylibVector3(up), size, origin, rotation, toRaylibColor(tint));
}



Font GetFontDefault() {
    return ::GetFontDefault();
}
Font LoadFont(const char* fileName) {
    return ::LoadFont(fileName);
}
Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount) {
    return ::LoadFontEx(fileName, fontSize, codepoints, codepointCount);
}
Font LoadFontFromImage(Image image, graphics::Color key, int firstChar) {
    return ::LoadFontFromImage(image, toRaylibColor(key), firstChar);
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
void DrawSplineLinear(const Vector2 *points, int pointCount, float thick, graphics::Color color) {
    ::DrawSplineLinear(points, pointCount, thick, toRaylibColor(color));
}
// Draw spline: B-Spline, minimum 4 points
void DrawSplineBasis(const Vector2 *points, int pointCount, float thick, graphics::Color color) {
    ::DrawSplineBasis(points, pointCount, thick, toRaylibColor(color));
}
// Draw spline: Catmull-Rom, minimum 4 points
void DrawSplineCatmullRom(const Vector2 *points, int pointCount, float thick, graphics::Color color) {
    ::DrawSplineCatmullRom(points, pointCount, thick, toRaylibColor(color));
}
// Draw spline: Quadratic Bezier, minimum 3 points
void DrawSplineBezierQuadratic(const Vector2 *points, int pointCount, float thick, graphics::Color color) {
    ::DrawSplineBezierQuadratic(points, pointCount, thick, toRaylibColor(color));
}
// Draw spline: Cubic Bezier, minimum 4 points
void DrawSplineBezierCubic(const Vector2 *points, int pointCount, float thick, graphics::Color color) {
    ::DrawSplineBezierCubic(points, pointCount, thick, toRaylibColor(color));
}
// Draw spline segment: Linear, 2 points
void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, graphics::Color color) {
    ::DrawSplineSegmentLinear(p1, p2, thick, toRaylibColor(color));
}
// Draw spline segment: B-Spline, 4 points
void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, graphics::Color color) {
    ::DrawSplineSegmentBasis(p1, p2, p3, p4, thick, toRaylibColor(color));
}
// Draw spline segment: Catmull-Rom, 4 points
void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, graphics::Color color) {
    ::DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, toRaylibColor(color));
}
// Draw spline segment: Quadratic Bezier, 2 points, 1 control point
void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, graphics::Color color) {
    ::DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, toRaylibColor(color));
}
// Draw spline segment: Cubic Bezier, 2 points, 2 control points
void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, graphics::Color color) {
    ::DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, toRaylibColor(color));
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
void DrawRectangleRec(Rectangle rec, graphics::Color color) {
    ::DrawRectangleRec(rec, toRaylibColor(color));
}
// Draw a color-filled rectangle with pro parameters
void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, graphics::Color color) {
    ::DrawRectanglePro(rec, origin, rotation, toRaylibColor(color));
}
// Draw a vertical-gradient-filled rectangle
void DrawRectangleGradientV(int posX, int posY, int width, int height, graphics::Color top, graphics::Color bottom) {
    ::DrawRectangleGradientV(posX, posY, width, height, toRaylibColor(top), toRaylibColor(bottom));
}
// Draw a horizontal-gradient-filled rectangle
void DrawRectangleGradientH(int posX, int posY, int width, int height, graphics::Color left, graphics::Color right) {
    ::DrawRectangleGradientH(posX, posY, width, height, toRaylibColor(left), toRaylibColor(right));
}
// Draw a gradient-filled rectangle with custom vertex colors
void DrawRectangleGradientEx(Rectangle rec, graphics::Color topLeft, graphics::Color bottomLeft, graphics::Color topRight, graphics::Color bottomRight) {
    ::DrawRectangleGradientEx(rec, toRaylibColor(topLeft), toRaylibColor(bottomLeft), toRaylibColor(topRight), toRaylibColor(bottomRight));
}
// Draw rectangle outline
void DrawRectangleLines(int posX, int posY, int width, int height, graphics::Color color) {
    ::DrawRectangleLines(posX, posY, width, height, toRaylibColor(color));
}
// Draw rectangle outline with extended parameters
void DrawRectangleLinesEx(Rectangle rec, float lineThick, graphics::Color color) {
    ::DrawRectangleLinesEx(rec, lineThick, toRaylibColor(color));
}
// Draw rectangle with rounded edges
void DrawRectangleRounded(Rectangle rec, float roundness, int segments, graphics::Color color) {
    ::DrawRectangleRounded(rec, roundness, segments, toRaylibColor(color));
}
// Draw rectangle lines with rounded edges
void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, graphics::Color color) {
    ::DrawRectangleRoundedLines(rec, roundness, segments, toRaylibColor(color));
}
// Draw rectangle with rounded edges outline with extended parameters
void DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, graphics::Color color) {
    ::DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, toRaylibColor(color));
}
// Draw a color-filled triangle
void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, graphics::Color color) {
    ::DrawTriangle(v1, v2, v3, toRaylibColor(color));
}
// Draw triangle outline
void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, graphics::Color color) {
    ::DrawTriangleLines(v1, v2, v3, toRaylibColor(color));
}
// Draw a triangle fan defined by points
void DrawTriangleFan(const Vector2 *points, int pointCount, graphics::Color color) {
    ::DrawTriangleFan(points, pointCount, toRaylibColor(color));
}
// Draw a triangle strip defined by points
void DrawTriangleStrip(const Vector2 *points, int pointCount, graphics::Color color) {
    ::DrawTriangleStrip(points, pointCount, toRaylibColor(color));
}
// Draw a regular polygon
void DrawPoly(Vector2 center, int sides, float radius, float rotation, graphics::Color color) {
    ::DrawPoly(center, sides, radius, rotation, toRaylibColor(color));
}
// Draw a polygon outline
void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, graphics::Color color) {
    ::DrawPolyLines(center, sides, radius, rotation, toRaylibColor(color));
}
// Draw a polygon outline with extended parameters
void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, graphics::Color color) {
    ::DrawPolyLinesEx(center, sides, radius, rotation, lineThick, toRaylibColor(color));
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
void DrawPixel(int posX, int posY, graphics::Color color) {
    ::DrawPixel(posX, posY, toRaylibColor(color));
}
// Draw a pixel (Vector version)
void DrawPixelV(Vector2 position, graphics::Color color) {
    ::DrawPixelV(position, toRaylibColor(color));
}
// Draw a line
void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, ::Color color) {
    ::DrawLine(startPosX, startPosY, endPosX, endPosY, color);
}
// Draw a line (using Vector2 positions)
void DrawLineV(Vector2 startPos, Vector2 endPos, graphics::Color color) {
    ::DrawLineV(startPos, endPos, toRaylibColor(color));
}
// Draw a line with thickness
void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, graphics::Color color) {
    ::DrawLineEx(startPos, endPos, thick, toRaylibColor(color));
}
// Draw lines sequence
void DrawLineStrip(const Vector2 *points, int pointCount, graphics::Color color) {
    ::DrawLineStrip(points, pointCount, toRaylibColor(color));
}
// Draw a cubic-bezier line
void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, graphics::Color color) {
    ::DrawLineBezier(startPos, endPos, thick, toRaylibColor(color));
}
// Draw a filled circle
void DrawCircle(int centerX, int centerY, float radius, ::Color color) {
    ::DrawCircle(centerX, centerY, radius, color);
}
// Draw a sector of a circle
void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, graphics::Color color) {
    ::DrawCircleSector(center, radius, startAngle, endAngle, segments, toRaylibColor(color));
}
// Draw circle sector outline
void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, graphics::Color color) {
    ::DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, toRaylibColor(color));
}
// Draw a gradient-filled circle
void DrawCircleGradient(int centerX, int centerY, float radius, graphics::Color inner, graphics::Color outer) {
    ::DrawCircleGradient(centerX, centerY, radius, toRaylibColor(inner), toRaylibColor(outer));
}
// Draw a filled circle (Vector version)
void DrawCircleV(Vector2 center, float radius, graphics::Color color) {
    ::DrawCircleV(center, radius, toRaylibColor(color));
}
// Draw circle outline
void DrawCircleLines(int centerX, int centerY, float radius, ::Color color) {
    ::DrawCircleLines(centerX, centerY, radius, color);
}
// Draw circle outline (Vector version)
void DrawCircleLinesV(Vector2 center, float radius, graphics::Color color) {
    ::DrawCircleLinesV(center, radius, toRaylibColor(color));
}
// Draw an ellipse
void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, ::Color color) {
    ::DrawEllipse(centerX, centerY, radiusH, radiusV, color);
}
// Draw ellipse outline
void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, ::Color color) {
    ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
}
// Draw a ring
void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, ::Color color) {
    ::DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}
// Draw ring outline
void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, ::Color color) {
    ::DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
}
// Draw a rectangle
void DrawRectangle(int posX, int posY, int width, int height, ::Color color) {
    ::DrawRectangle(posX, posY, width, height, color);
}
// Draw a rectangle (Vector version)
void DrawRectangleV(Vector2 position, Vector2 size, ::Color color) {
    ::DrawRectangleV(position, size, color);
}

// Set background color (framebuffer clear color)
void ClearBackground(graphics::Color color) {
    ::ClearBackground(toRaylibColor(color));
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
void DrawSphereWires(math::Vector3 centerPos, float radius, int rings, int slices, graphics::Color color) {
    ::DrawSphereWires(toRaylibVector3(centerPos), radius, rings, slices, toRaylibColor(color));
}
// Draw a cylinder/cone
void DrawCylinder(math::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, graphics::Color color) {
    ::DrawCylinder(toRaylibVector3(position), radiusTop, radiusBottom, height, slices, toRaylibColor(color));
}
// Draw a cylinder with base at startPos and top at endPos
void DrawCylinderEx(math::Vector3 startPos, math::Vector3 endPos, float startRadius, float endRadius, int sides, graphics::Color color) {
    ::DrawCylinderEx(toRaylibVector3(startPos), toRaylibVector3(endPos), startRadius, endRadius, sides, toRaylibColor(color));
}
// Draw cylinder/cone wires
void DrawCylinderWires(math::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, graphics::Color color) {
    ::DrawCylinderWires(toRaylibVector3(position), radiusTop, radiusBottom, height, slices, toRaylibColor(color));
}
// Draw cylinder wires with base at startPos and top at endPos
void DrawCylinderWiresEx(math::Vector3 startPos, math::Vector3 endPos, float startRadius, float endRadius, int sides, graphics::Color color) {
    ::DrawCylinderWiresEx(toRaylibVector3(startPos), toRaylibVector3(endPos), startRadius, endRadius, sides, toRaylibColor(color));
}
// Draw a capsule with the center of its sphere caps at startPos and endPos
void DrawCapsule(math::Vector3 startPos, math::Vector3 endPos, float radius, int slices, int rings, graphics::Color color) {
    ::DrawCapsule(toRaylibVector3(startPos), toRaylibVector3(endPos), radius, slices, rings, toRaylibColor(color));
}
// Draw capsule wireframe with the center of its sphere caps at startPos and endPos
void DrawCapsuleWires(math::Vector3 startPos, math::Vector3 endPos, float radius, int slices, int rings, graphics::Color color) {
    ::DrawCapsuleWires(toRaylibVector3(startPos), toRaylibVector3(endPos), radius, slices, rings, toRaylibColor(color));
}
// Draw a plane on the XZ axis
void DrawPlane(math::Vector3 centerPos, Vector2 size, graphics::Color color) {
    ::DrawPlane(toRaylibVector3(centerPos), size, toRaylibColor(color));
}
// Draw a ray line
void DrawRay(Ray ray, graphics::Color color) {
    ::DrawRay(ray, toRaylibColor(color));
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
void DrawLine3D(math::Vector3 startPos, math::Vector3 endPos, graphics::Color color) {
    ::DrawLine3D(toRaylibVector3(startPos), toRaylibVector3(endPos), toRaylibColor(color));
}
// Draw a point in 3D space, actually a small line
void DrawPoint3D(math::Vector3 position, graphics::Color color) {
    ::DrawPoint3D(toRaylibVector3(position), toRaylibColor(color));
}
// Draw a circle in 3D world space
void DrawCircle3D(math::Vector3 center, float radius, math::Vector3 rotationAxis, float rotationAngle, graphics::Color color) {
    ::DrawCircle3D(toRaylibVector3(center), radius, toRaylibVector3(rotationAxis), rotationAngle, toRaylibColor(color));
}
// Draw a color-filled triangle (vertex in counter-clockwise order!)
void DrawTriangle3D(math::Vector3 v1, math::Vector3 v2, math::Vector3 v3, graphics::Color color) {
    ::DrawTriangle3D(toRaylibVector3(v1), toRaylibVector3(v2), toRaylibVector3(v3), toRaylibColor(color));
}
// Draw a triangle strip defined by points
void DrawTriangleStrip3D(const Vector3 *points, int pointCount, graphics::Color color) {
    ::DrawTriangleStrip3D(points, pointCount, toRaylibColor(color));
}
// Draw a cube
void DrawCube(math::Vector3 position, float width, float height, float length, graphics::Color color) {
    ::DrawCube(toRaylibVector3(position), width, height, length, toRaylibColor(color));
}
// Draw cube (Vector version)
void DrawCubeV(math::Vector3 position, math::Vector3 size, graphics::Color color) {
    ::DrawCubeV(toRaylibVector3(position), toRaylibVector3(size), toRaylibColor(color));
}
// Draw cube wires
void DrawCubeWires(math::Vector3 position, float width, float height, float length, graphics::Color color) {
    ::DrawCubeWires(toRaylibVector3(position), width, height, length, toRaylibColor(color));
}
// Draw cube wires (Vector version)
void DrawCubeWiresV(math::Vector3 position, math::Vector3 size, graphics::Color color) {
    ::DrawCubeWiresV(toRaylibVector3(position), toRaylibVector3(size), toRaylibColor(color));
}
// Draw sphere
void DrawSphere(math::Vector3 centerPos, float radius, graphics::Color color) {
    ::DrawSphere(toRaylibVector3(centerPos), radius, toRaylibColor(color));
}
// Draw sphere with extended parameters
void DrawSphereEx(math::Vector3 centerPos, float radius, int rings, int slices, graphics::Color color) {
    ::DrawSphereEx(toRaylibVector3(centerPos), radius, rings, slices, toRaylibColor(color));
}
void DrawFPS(int posX, int posY) {
    ::DrawFPS(posX, posY);
}
void DrawText(const char* text, int posX, int posY, int fontSize, graphics::Color color) {
    ::DrawText(text, posX, posY, fontSize, toRaylibColor(color));
}
void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, graphics::Color tint) {
    ::DrawTextEx(font, text, position, fontSize, spacing, toRaylibColor(tint));
}
void DrawTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, graphics::Color tint) {
    ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, toRaylibColor(tint));
}
void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, graphics::Color tint) {
    ::DrawTextCodepoint(font, codepoint, position, fontSize, toRaylibColor(tint));
}
void DrawTextCodepoints(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, graphics::Color tint) {
    ::DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, toRaylibColor(tint));
}
void UpdateCamera(Camera *camera, int mode){
    ::UpdateCamera(camera, mode);
};      // Update camera position for selected mode

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


} // namespace raylib
