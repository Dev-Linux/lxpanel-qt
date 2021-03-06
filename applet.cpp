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


#include "applet.h"
#include "appletinfo.h"
#include <QMenu>

using namespace Lxpanel;

Applet::Applet(AppletInfo* info, QWidget* parent):
  info_(info),
  expand_(false) {

}

Applet::~Applet() {

}

// set default context menu handling for the applet
void Applet::customizeContextMenu(QMenu* menu) {
  QAction* action = menu->addAction(tr("Configure \"%1\"").arg(info()->name()));
  connect(action, SIGNAL(triggered(bool)), SLOT(preferences()));
}

void Applet::preferences() {
}


#include "applet.moc"
