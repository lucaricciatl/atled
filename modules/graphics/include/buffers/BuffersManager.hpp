// BuffersManager.hpp

#ifndef BUFFERSMANAGER_HPP
#define BUFFERSMANAGER_HPP

#include <memory>
#include <string>
#include <vector>
#include "Buffer2D.hpp"

namespace graphics {

	enum BufferType { POINT2D, LINE2D, POLY2D };
class BuffersManager {
 public:
  BuffersManager();
  ~BuffersManager();

  // Create a new buffer of a specified type and add it to the manager
  std::shared_ptr<Buffer2D> createBuffer(const BufferType type);

  // Delete a buffer from the manager
  void deleteBuffer(const std::shared_ptr<Buffer2D>& buffer);

  // Get all buffers
  const std::vector<std::shared_ptr<Buffer2D>>& getBuffers() const;

 private:
  std::vector<std::shared_ptr<Buffer2D>> mBuffers;
};

}  // namespace graphics

#endif  // BUFFERSMANAGER_HPP
