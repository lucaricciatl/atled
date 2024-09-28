#include "raylib.h"
#include "rlgl.h"
#include "types.hpp"

namespace gfx {


int GetScreenWidth(void) {
    return ::GetScreenWidth();  // Calls Raylib's GetScreenWidth
}

int GetScreenHeight(void) {
    return ::GetScreenHeight();  // Calls Raylib's GetScreenHeight
}

int GetRenderWidth(void) {
    return ::GetRenderWidth();  // Calls Raylib's GetRenderWidth
}

int GetRenderHeight(void) {
    return ::GetRenderHeight();  // Calls Raylib's GetRenderHeight
}

int GetMonitorCount(void) {
    return ::GetMonitorCount();  // Calls Raylib's GetMonitorCount
}

int GetCurrentMonitor(void) {
    return ::GetCurrentMonitor();  // Calls Raylib's GetCurrentMonitor
}

Vector2 GetMonitorPosition(int monitor) {
    return ::GetMonitorPosition(monitor);  // Calls Raylib's GetMonitorPosition
}

int GetMonitorWidth(int monitor) {
    return ::GetMonitorWidth(monitor);  // Calls Raylib's GetMonitorWidth
}

int GetMonitorHeight(int monitor) {
    return ::GetMonitorHeight(monitor);  // Calls Raylib's GetMonitorHeight
}

int GetMonitorPhysicalWidth(int monitor) {
    return ::GetMonitorPhysicalWidth(monitor);  // Calls Raylib's GetMonitorPhysicalWidth
}

int GetMonitorPhysicalHeight(int monitor) {
    return ::GetMonitorPhysicalHeight(monitor);  // Calls Raylib's GetMonitorPhysicalHeight
}

int GetMonitorRefreshRate(int monitor) {
    return ::GetMonitorRefreshRate(monitor);  // Calls Raylib's GetMonitorRefreshRate
}

Vector2 GetWindowPosition(void) {
    return ::GetWindowPosition();  // Calls Raylib's GetWindowPosition
}

Vector2 GetWindowScaleDPI(void) {
    return ::GetWindowScaleDPI();  // Calls Raylib's GetWindowScaleDPI
}

const char *GetMonitorName(int monitor) {
    return ::GetMonitorName(monitor);  // Calls Raylib's GetMonitorName
}

void SetClipboardText(const char *text) {
    ::SetClipboardText(text);  // Calls Raylib's SetClipboardText
}

const char *GetClipboardText(void) {
    return ::GetClipboardText();  // Calls Raylib's GetClipboardText
}

void EnableEventWaiting(void) {
    ::EnableEventWaiting();  // Calls Raylib's EnableEventWaiting
}

void DisableEventWaiting(void) {
    ::DisableEventWaiting();  // Calls Raylib's DisableEventWaiting
}

} // namespace gfx

namespace gfx {

void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color) {
    ::DrawLine3D(startPos, endPos, color);  // Calls Raylib's DrawLine3D
}

void DrawPoint3D(Vector3 position, Color color) {
    ::DrawPoint3D(position, color);  // Calls Raylib's DrawPoint3D
}

void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
    ::DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);  // Calls Raylib's DrawCircle3D
}

void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color) {
    ::DrawTriangle3D(v1, v2, v3, color);  // Calls Raylib's DrawTriangle3D
}

void DrawTriangleStrip3D(const Vector3 *points, int pointCount, Color color) {
    ::DrawTriangleStrip3D(points, pointCount, color);  // Calls Raylib's DrawTriangleStrip3D
}

void DrawCube(Vector3 position, float width, float height, float length, Color color) {
    ::DrawCube(position, width, height, length, color);  // Calls Raylib's DrawCube
}

void DrawCubeV(Vector3 position, Vector3 size, Color color) {
    ::DrawCubeV(position, size, color);  // Calls Raylib's DrawCubeV
}

void DrawCubeWires(Vector3 position, float width, float height, float length, Color color) {
    ::DrawCubeWires(position, width, height, length, color);  // Calls Raylib's DrawCubeWires
}

void DrawCubeWiresV(Vector3 position, Vector3 size, Color color) {
    ::DrawCubeWiresV(position, size, color);  // Calls Raylib's DrawCubeWiresV
}

void DrawSphere(Vector3 centerPos, float radius, Color color) {
    ::DrawSphere(centerPos, radius, color);  // Calls Raylib's DrawSphere
}

void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    ::DrawSphereEx(centerPos, radius, rings, slices, color);  // Calls Raylib's DrawSphereEx
}

void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    ::DrawSphereWires(centerPos, radius, rings, slices, color);  // Calls Raylib's DrawSphereWires
}

void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    ::DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);  // Calls Raylib's DrawCylinder
}

void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    ::DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);  // Calls Raylib's DrawCylinderEx
}

void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    ::DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);  // Calls Raylib's DrawCylinderWires
}

void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    ::DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);  // Calls Raylib's DrawCylinderWiresEx
}

void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
    ::DrawCapsule(startPos, endPos, radius, slices, rings, color);  // Calls Raylib's DrawCapsule
}

void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
    ::DrawCapsuleWires(startPos, endPos, radius, slices, rings, color);  // Calls Raylib's DrawCapsuleWires
}
}


namespace gfx {

void TakeScreenshot(const char *fileName) {
    ::TakeScreenshot(fileName);  // Calls Raylib's TakeScreenshot
}

void SetConfigFlags(unsigned int flags) {
    ::SetConfigFlags(flags);  // Calls Raylib's SetConfigFlags
}

void OpenURL(const char *url) {
    ::OpenURL(url);  // Calls Raylib's OpenURL
}

} // namespace gfx



namespace gfx {

void ClearBackground(Color color) {
    ::ClearBackground(color);  // Calls Raylib's ClearBackground
}

void BeginDrawing(void) {
    ::BeginDrawing();  // Calls Raylib's BeginDrawing
}

void EndDrawing(void) {
    ::EndDrawing();  // Calls Raylib's EndDrawing
}

void BeginMode2D(Camera2D camera) {
    ::BeginMode2D(camera);  // Calls Raylib's BeginMode2D
}

void EndMode2D(void) {
    ::EndMode2D();  // Calls Raylib's EndMode2D
}

void BeginMode3D(Camera3D camera) {
    ::BeginMode3D(camera);  // Calls Raylib's BeginMode3D
}

void EndMode3D(void) {
    ::EndMode3D();  // Calls Raylib's EndMode3D
}

void BeginTextureMode(RenderTexture2D target) {
    ::BeginTextureMode(target);  // Calls Raylib's BeginTextureMode
}

void EndTextureMode(void) {
    ::EndTextureMode();  // Calls Raylib's EndTextureMode
}

void BeginShaderMode(Shader shader) {
    ::BeginShaderMode(shader);  // Calls Raylib's BeginShaderMode
}

void EndShaderMode(void) {
    ::EndShaderMode();  // Calls Raylib's EndShaderMode
}

void BeginBlendMode(int mode) {
    ::BeginBlendMode(mode);  // Calls Raylib's BeginBlendMode
}

void EndBlendMode(void) {
    ::EndBlendMode();  // Calls Raylib's EndBlendMode
}

void BeginScissorMode(int x, int y, int width, int height) {
    ::BeginScissorMode(x, y, width, height);  // Calls Raylib's BeginScissorMode
}

void EndScissorMode(void) {
    ::EndScissorMode();  // Calls Raylib's EndScissorMode
}

void BeginVrStereoMode(VrStereoConfig config) {
    ::BeginVrStereoMode(config);  // Calls Raylib's BeginVrStereoMode
}

void EndVrStereoMode(void) {
    ::EndVrStereoMode();  // Calls Raylib's EndVrStereoMode
}

} // namespace gfx




namespace gfx {

void rlBegin(int mode) {
    ::rlBegin(mode);  // Calls Raylib's rlBegin
}

void rlEnd(void) {
    ::rlEnd();  // Calls Raylib's rlEnd
}

void rlVertex2i(int x, int y) {
    ::rlVertex2i(x, y);  // Calls Raylib's rlVertex2i
}

void rlVertex2f(float x, float y) {
    ::rlVertex2f(x, y);  // Calls Raylib's rlVertex2f
}

void rlVertex3f(float x, float y, float z) {
    ::rlVertex3f(x, y, z);  // Calls Raylib's rlVertex3f
}

void rlTexCoord2f(float x, float y) {
    ::rlTexCoord2f(x, y);  // Calls Raylib's rlTexCoord2f
}

void rlNormal3f(float x, float y, float z) {
    ::rlNormal3f(x, y, z);  // Calls Raylib's rlNormal3f
}

void rlColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    ::rlColor4ub(r, g, b, a);  // Calls Raylib's rlColor4ub
}

void rlColor3f(float x, float y, float z) {
    ::rlColor3f(x, y, z);  // Calls Raylib's rlColor3f
}

void rlColor4f(float x, float y, float z, float w) {
    ::rlColor4f(x, y, z, w);  // Calls Raylib's rlColor4f
}

} // namespace gfx
