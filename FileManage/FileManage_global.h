#ifndef FILEMANAGE_GLOBAL_H
#define FILEMANAGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FILEMANAGE_LIBRARY)
#   define FILEMANAGE_EXPORT Q_DECL_EXPORT
#else
#   define FILEMANAGE_EXPORT Q_DECL_IMPORT
#endif

#endif // FILEMANAGE_GLOBAL_H
