
#ifndef _OgreOctreePluginExport_H
#define _OgreOctreePluginExport_H

#ifdef PLUGIN_OCTREESCENEMANAGER_STATIC_DEFINE
#  define _OgreOctreePluginExport
#  define PLUGIN_OCTREESCENEMANAGER_NO_EXPORT
#else
#  ifndef _OgreOctreePluginExport
#    ifdef Plugin_OctreeSceneManager_EXPORTS
        /* We are building this library */
#      define _OgreOctreePluginExport __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define _OgreOctreePluginExport __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef PLUGIN_OCTREESCENEMANAGER_NO_EXPORT
#    define PLUGIN_OCTREESCENEMANAGER_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef PLUGIN_OCTREESCENEMANAGER_DEPRECATED
#  define PLUGIN_OCTREESCENEMANAGER_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PLUGIN_OCTREESCENEMANAGER_DEPRECATED_EXPORT
#  define PLUGIN_OCTREESCENEMANAGER_DEPRECATED_EXPORT _OgreOctreePluginExport PLUGIN_OCTREESCENEMANAGER_DEPRECATED
#endif

#ifndef PLUGIN_OCTREESCENEMANAGER_DEPRECATED_NO_EXPORT
#  define PLUGIN_OCTREESCENEMANAGER_DEPRECATED_NO_EXPORT PLUGIN_OCTREESCENEMANAGER_NO_EXPORT PLUGIN_OCTREESCENEMANAGER_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define PLUGIN_OCTREESCENEMANAGER_NO_DEPRECATED
#endif

#endif