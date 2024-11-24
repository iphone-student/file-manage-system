﻿#ifndef MAINWINDOW_GLOBAL_H
#define MAINWINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAINWINDOW_LIBRARY)
#   define MAINWINDOW_EXPORT Q_DECL_EXPORT
#else
#   define MAINWINDOW_EXPORT Q_DECL_IMPORT
#endif

#endif // MAINWINDOW_GLOBAL_H