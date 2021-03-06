/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmConfigureFileCommand_h
#define cmConfigureFileCommand_h

#include "cmCommand.h"

class cmConfigureFileCommand : public cmCommand
{
public:
  cmTypeMacro(cmConfigureFileCommand, cmCommand);

  cmCommand* Clone() CM_OVERRIDE { return new cmConfigureFileCommand; }

  /**
   * This is called when the command is first encountered in
   * the input file.
   */
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) CM_OVERRIDE;

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "configure_file"; }

  /**
   * This determines if the command is invoked when in script mode.
   */
  bool IsScriptable() const CM_OVERRIDE { return true; }

private:
  int ConfigureFile();

  cmNewLineStyle NewLineStyle;

  std::string InputFile;
  std::string OutputFile;
  bool CopyOnly;
  bool EscapeQuotes;
  bool AtOnly;
};

#endif
