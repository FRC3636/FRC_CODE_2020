/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShootBalls
    : public frc2::CommandHelper<frc2::CommandBase, ShootBalls> {
 public:
  ShootBalls(Shooter* shooter, std::function<bool()> moveBalls, std::function<bool()> end);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  Shooter* m_shooter;
  std::function<bool()> m_moveBalls;
  std::function<bool()> m_end;
};
