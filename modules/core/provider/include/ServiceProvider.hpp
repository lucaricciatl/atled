#ifndef SERVICE_PROVIDER_HPP
#define SERVICE_PROVIDER_HPP

#include <memory>
#include <IGraphicManager.hpp>
#include <InputManager.hpp>
#include <CameraManager.hpp> // Ensure CameraManager is included

class ServiceProvider {
public:
	void Provide(std::shared_ptr<input::InputManager> inputMgr);
	void Provide(std::shared_ptr<graphics::IGraphicManager> graphicsMgr);
	void Provide(std::shared_ptr<graphics::CameraManager> cameraMgr);

	std::shared_ptr<input::InputManager> GetInputManager() const;
	std::shared_ptr<graphics::IGraphicManager> GetGraphicManager() const;
	std::shared_ptr<graphics::CameraManager> GetCameraManager() const;

private:
	std::shared_ptr<input::InputManager> inputManager;
	std::shared_ptr<graphics::IGraphicManager> graphicsManager;
	std::shared_ptr<graphics::CameraManager> cameraManager;
};

#endif // SERVICE_PROVIDER_HPP