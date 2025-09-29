#include "ProgressBar.hpp"
#include <iostream>

namespace logging {

ProgressBar::ProgressBar(int total, int barWidth, ProgressBarStyle style)
    : total_(total), barWidth_(barWidth), lastProgress_(0), style_(style)
{
    update(0);
}

void ProgressBar::setStyle(ProgressBarStyle style)
{
    std::lock_guard<std::mutex> lock(mutex_);
    style_ = style;
    printProgress(lastProgress_);
}

void ProgressBar::update(int progress)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (progress < 0)
        progress = 0;
    if (progress > total_)
        progress = total_;

    lastProgress_ = progress;
    printProgress(progress);
}

void ProgressBar::finish()
{
    std::lock_guard<std::mutex> lock(mutex_);
    lastProgress_ = total_;
    printProgress(total_);
    std::cout << std::endl;
}

void ProgressBar::printProgress(int progress)
{
    float fraction = static_cast<float>(progress) / total_;
    int pos = static_cast<int>(barWidth_ * fraction);

    std::cout << "\r";
    for (int i = 0; i < barWidth_; ++i)
    {
        if (style_ == ProgressBarStyle::WhiteBlock) {
            if (i < pos)
                // Using full white block character (Unicode U+2588)
                std::cout << "\u2588";
            else
                std::cout << " ";
        }
        else { // Arrow style
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
    }
    std::cout << "\t" << static_cast<int>(fraction * 100.0f) << " %";
    std::cout.flush();
}

} // namespace logging