#pragma once

#include "moving_object.h"
#include "movable_character.h"

class AbstractGhost : public MovableCharacter, public MovingObject
{
Q_OBJECT

public:
    AbstractGhost(const Coordinates& coordinates, Direction initialDirection);
    ~AbstractGhost() override = 0;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void advanceAnimation() override;
    void reset() override;

    void resetScaredState()
    { scaredState_ = ScaredState::NO_SCARED; }

    void setScaredBlueState()
    { scaredState_ = ScaredState::SCARED_BLUE; }

    void setScaredWhiteState()
    { scaredState_ = ScaredState::SCARED_WHITE; }

    [[nodiscard]] bool isScared() const;
    [[nodiscard]] bool isScaredWhite() const;
    [[nodiscard]] bool isScaredBlue() const;

    [[nodiscard]] bool canMoveAgain() const
    { return canMoveAgain_; }

    [[nodiscard]] int getSkippedMoves() const
    {return skippedMoves_;}

    void incrementSkippedMoves();
    void resetSkippedMoves();

protected:
    void loadImages(const std::array<std::string, 12>& imagesUrls);

    bool canMoveAgain_{};

private slots:
    void resetCanMoveAgain();

private:
    enum class ScaredState
    {
        NO_SCARED, SCARED_BLUE, SCARED_WHITE
    } scaredState_;

    QPixmap left1Pixmap_, left2Pixmap_, up1Pixmap_, up2Pixmap_, down1Pixmap_, down2Pixmap_, right1Pixmap_, right2Pixmap_;
    QPixmap scaredBlue1Pixmap_, scaredBlue2Pixmap_;
    QPixmap scaredWhite1Pixmap_, scaredWhite2Pixmap_;

    int skippedMoves_{};
};
