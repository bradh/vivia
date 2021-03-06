/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vpActivityConfig_h
#define __vpActivityConfig_h

#include "vpEntityConfig.h"

class QSettings;

class vgActivityType;
class vtkVgActivityTypeRegistry;

class vpActivityConfig : public vpEntityConfig
{
public:
  vpActivityConfig(vtkVgActivityTypeRegistry* registry);
  virtual ~vpActivityConfig();

  virtual int GetNumberOfTypes();

  virtual const vgEntityType& GetEntityType(int id);
  virtual void SetEntityType(int id, const vgEntityType& type);

  virtual void MarkTypeUsed(int index);
  virtual void MarkAllTypesUnused();

  const vgActivityType& GetActivityType(int id);
  void SetActivityType(int id, const vgActivityType& type);

  int GetId(const char* idString);

  void LoadFromFile(const char* filename);

  static int GetDisplayModeFromString(const char* str);

protected:
  void ReadActivityTypes(QSettings& settings);
  void WriteActivityTypes();

  void SetupBuiltInTypes();

  int GetIdInternal(const char* idString);

private:
  class vpActivityConfigInternal;
  vpActivityConfigInternal* Internal;

  vtkVgActivityTypeRegistry* ActivityTypeRegistry;

private:
  vpActivityConfig(const vpActivityConfig& src);  // Not implemented.
  void operator=(const vpActivityConfig& src);    // Not implemented.
};

#endif // __vpActivityConfig_h
