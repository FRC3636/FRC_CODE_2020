/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Intake.h>
#include <subsystems/Shooter.h>
#include <subsystems/Conveyor.h>
#include "Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

// ########## REVIEW ##########
// Now that I've divided Intake in two subsystems, what you need is no longer the Intake but the Conveyor

class ShootInAuto
    : public frc2::CommandHelper<frc2::CommandBase, ShootInAuto> {
 public:
  ShootInAuto(Conveyor* conveyor, Shooter* shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  Conveyor* m_conveyor;
  Shooter* m_shooter;
  std::chrono::system_clock::time_point m_startTime;
  std::chrono::duration<double> m_duration;
};
