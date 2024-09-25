#include "raylib.h"

namespace types{
// Vector2, 2 components
//struct Vector2;
// Vector3, 3 components
//struct Vector3;
// Vector4, 4 components
//struct Vector4;

// Quaternion, 4 components (Vector4 alias)
//Vector4 Quaternion;

// Matrix, 4x4 components, column major, OpenGL style, right-handed
struct Matrix;

// Color, 4 components, R8G8B8A8 (32bit)
struct Color;

// Rectangle, 4 components
struct Rectangle;

// Image, pixel data stored in CPU memory (RAM)
struct Image;

// Texture, tex data stored in GPU memory (VRAM)
struct Texture;

// RenderTexture, fbo for texture rendering
struct RenderTexture;

// RenderTexture2D, same as RenderTexture
RenderTexture;

// NPatchInfo, n-patch layout info
struct NPatchInfo;

// GlyphInfo, font characters glyphs info
struct GlyphInfo;

// Font, font texture and GlyphInfo array data
struct Font;

// Camera, defines position/orientation in 3d space
struct Camera3D;

// Camera2D, defines position/orientation in 2d space
struct Camera2D;

// Mesh, vertex data and vao/vbo
struct Mesh;

// Shader
struct Shader;

// MaterialMap
struct MaterialMap;

// Material, includes shader and maps
struct Material;
// Transform, vertex transformation data
struct Transform;

// Bone, skeletal animation bone
struct BoneInfo;

// Model, meshes, materials and animation data
struct Model;

// ModelAnimation
struct ModelAnimation;

// Ray, ray for raycasting
struct Ray;

// RayCollision, ray hit information
struct RayCollision;

// BoundingBox
struct BoundingBox;

// Wave, audio wave data
struct Wave;

// Opaque structs declaration
// NOTE: Actual structs are defined internally in raudio module
struct rAudioBuffer;
struct rAudioProcessor;

// AudioStream, custom audio stream
struct AudioStream;

// Sound
struct Sound;

// Music, audio stream, anything longer than ~10 seconds should be streamed
struct Music;

// VrDeviceInfo, Head-Mounted-Display device parameters
struct VrDeviceInfo;

// VrStereoConfig, VR stereo rendering configuration for simulator
struct VrStereoConfig;

// File path list
struct FilePathList;

// Automation event
struct AutomationEvent;

// Automation event list
struct AutomationEventList;


typedef enum KeyboardKey;
}