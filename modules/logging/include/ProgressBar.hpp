#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <mutex>

namespace logging {

enum class ProgressBarStyle {
    WhiteBlock,
    Arrow
};

class ProgressBar {
public:
    ProgressBar(int total, int barWidth = 50, ProgressBarStyle style = ProgressBarStyle::WhiteBlock);
    void update(int progress);
    void finish();
    void setStyle(ProgressBarStyle style);
    
private:
    int total_;
    int barWidth_;
    int lastProgress_;
    ProgressBarStyle style_;
    std::mutex mutex_;
    void printProgress(int progress);
};

} // namespace logging

#endif // PROGRESSBAR_HPP