/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "taskinfo.h"
#include <QImage>

using namespace Lxpanel;

TaskInfo::TaskInfo(TaskManager* manager, Window window):
  manager_(manager),
  window_(window) {

}

TaskInfo::~TaskInfo() {

}

QPixmap TaskInfo::iconPixmap(int size) {
  QPixmap pixmap;
  xfitMan().getClientIcon(window_, pixmap);
  return pixmap;
}

#include <QX11Info>
TaskInfo::ChangeType TaskInfo::x11EventFilter(XEvent* event) {
  ChangeType change = NoChange;
  if(event->xproperty.atom == xfitMan().atom("_NET_WM_STATE"))
    change = TaskInfo::StateChanged;
  else if(event->xproperty.atom == xfitMan().atom("_NET_WM_VISIBLE_NAME") || event->xproperty.atom == xfitMan().atom("_NET_WM_NAME"))
    change = TaskInfo::TitleChanged;
  else if(event->xproperty.atom == xfitMan().atom("_NET_WM_ICON"))
    change = TaskInfo::IconChanged;
  return change;
}
