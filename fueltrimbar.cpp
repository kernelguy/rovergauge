#include <QStylePainter>
#include <QStyleOptionProgressBarV2>
#include <QFrame>
#include "fueltrimbar.h"

/**
 * Construct with fixed max and min values.
 */
FuelTrimBar::FuelTrimBar(QWidget *parent) :
    QProgressBar(parent),
    minimumVal(-256),
    maximumVal(255)

{
    this->setMaximum(maximumVal);
    this->setMinimum(minimumVal);
}

/**
 * Draws a progress bar that extends left or right from the center point.
 */
void FuelTrimBar::paintEvent(QPaintEvent *)
{
    int currentVal = this->value();
    QStylePainter painter(this);
    QStyleOptionProgressBarV2 bar;
    bar.initFrom(this);
    bar.minimum = minimumVal;
    bar.maximum = maximumVal;

    if (currentVal > maximumVal)
    {
        currentVal = maximumVal;
    }
    else if (currentVal < minimumVal)
    {
        currentVal = minimumVal;
    }

    style()->drawControl(QStyle::CE_ProgressBarGroove, &bar, &painter, this);

    // compute the dimensions and locations of the bar
    float percentOfWidth = (float)(qAbs(currentVal)) / (float)(maximumVal - minimumVal);
    int left = bar.rect.topLeft().x();
    int right = bar.rect.topRight().x();
    int top = bar.rect.topLeft().y();
    int height = bar.rect.bottomLeft().y() - top + 1;
    int barWidth = (right - left) * percentOfWidth;
    int midPoint = left + ((right - left) / 2);
    int startPoint = (currentVal >= 0) ? midPoint : midPoint - barWidth;

    bar.rect = QRect(startPoint, top, barWidth * 2, height);
    style()->drawControl(QStyle::CE_ProgressBarContents, &bar, &painter, this);
}
