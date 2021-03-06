/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  <copyright holder> <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef LXPANEL_APPLETPLUGINFACTORY_H
#define LXPANEL_APPLETPLUGINFACTORY_H

#include <QtPlugin>
#include "appletinfo.h"
#include "appletplugin.h"

namespace Lxpanel {

class AppletPlugin;

// class used to load dynamic modules on demand and generate new applet instances
class AppletPluginInfo : public AppletInfo {

public:
  AppletPluginInfo(QString id, QString moduleFile, QString desktopFile);
  virtual ~AppletPluginInfo();
  virtual Applet* create(QWidget* parent);

  // load information about this applet from desktop entry file
  bool loadInfo(QString desktopFile);

private:
  QString moduleFile_;
  AppletPlugin* plugin_;
};

}

#endif // LXPANEL_APPLETPLUGINFACTORY_H
