# SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: LGPL-3.0-or-later

include(GNUInstallDirs)

function(configure_files)
  foreach(input ${ARGV})
    configure_file(${input} ${input} @ONLY)
  endforeach()
endfunction()

configure_files(
  # find -regex '\.\/\(script\|share\|lib\|libexec\)\/.*' -type f -printf '%P\n'
  # | sort
  libexec/linglong/app-conf-generator
  libexec/linglong/builder/helper/config-check.sh
  libexec/linglong/builder/helper/ldd-check.sh
  libexec/linglong/builder/helper/main-check.sh
  libexec/linglong/fetch-archive-source
  libexec/linglong/fetch-dsc-source
  libexec/linglong/fetch-file-source
  libexec/linglong/fetch-git-source
  lib/linglong/container/config.d/10-basics.json
  lib/linglong/container/config.d/25-host-rootfs.json
  lib/linglong/container/config.d/25-host-statics.json
  lib/linglong/container/config.json
  lib/linglong/container/README.md
  lib/linglong/generate-xdg-data-dirs.sh
  lib/systemd/system-environment-generators/61-linglong
  lib/systemd/system/org.deepin.linglong.PackageManager.service
  lib/systemd/system-preset/91-linglong.preset
  lib/systemd/user/linglong-session-helper.service
  lib/sysusers.d/linglong.conf
  lib/tmpfiles.d/linglong.conf
  script/linglong.sh
  share/bash-completion/completions/ll-builder
  share/bash-completion/completions/ll-cli
  share/dbus-1/system.d/org.deepin.linglong.PackageManager.conf
  share/dbus-1/system-services/org.deepin.linglong.PackageManager.service
  share/linglong/builder/templates/example.yaml
  share/linglong/config.yaml
  share/mime/packages/deepin-linglong.xml
  share/polkit-1/actions/org.deepin.linglong.PackageManager.policy)

# bash-completion
set(BASH_COMPLETIONS_DIR ${CMAKE_INSTALL_DATADIR}/bash-completion)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/bash-completion/completions
        DESTINATION ${BASH_COMPLETIONS_DIR})

# dbus
set(DBUS_SYSTEM_BUS_DIR ${CMAKE_INSTALL_DATADIR}/dbus-1)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/dbus-1/system.d
        DESTINATION ${DBUS_SYSTEM_BUS_DIR})
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/dbus-1/system-services
        DESTINATION ${DBUS_SYSTEM_BUS_DIR})

# libexec
set(LIBEXEC_LINGLONG_DIR ${CMAKE_INSTALL_PREFIX}/libexec/linglong)
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/app-conf-generator
        DESTINATION ${LIBEXEC_LINGLONG_DIR})
install(
  PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/fetch-archive-source
  DESTINATION ${LIBEXEC_LINGLONG_DIR})
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/fetch-dsc-source
        DESTINATION ${LIBEXEC_LINGLONG_DIR})
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/fetch-file-source
        DESTINATION ${LIBEXEC_LINGLONG_DIR})
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/fetch-git-source
        DESTINATION ${LIBEXEC_LINGLONG_DIR})

# builder helpers
set(LIBEXEC_LINGLONG_BUILDER_DIR ${LIBEXEC_LINGLONG_DIR}/builder/helper)
install(
  PROGRAMS
    ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/builder/helper/config-check.sh
  DESTINATION ${LIBEXEC_LINGLONG_BUILDER_DIR})
install(
  PROGRAMS
    ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/builder/helper/ldd-check.sh
  DESTINATION ${LIBEXEC_LINGLONG_BUILDER_DIR})
install(
  PROGRAMS
    ${CMAKE_CURRENT_BINARY_DIR}/libexec/linglong/builder/helper/main-check.sh
  DESTINATION ${LIBEXEC_LINGLONG_BUILDER_DIR})

# linglong
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/00-id-mapping-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/00-id-mapping
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/05-initialize-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/05-initialize
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/20-devices-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/20-devices
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/25-host-env-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/25-host-env
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/30-user-home-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/30-user-home
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/40-host-ipc-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/40-host-ipc
     SYMBOLIC)
file(CREATE_LINK ${CMAKE_INSTALL_PREFIX}/libexec/linglong/90-legacy-static
     ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/90-legacy
     SYMBOLIC)

install(
  PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/generate-xdg-data-dirs.sh
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.json
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong/container)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/README.md
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong/container)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/10-basics.json
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong/container/config.d)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/25-host-rootfs.json
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong/container/config.d)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lib/linglong/container/config.d/25-host-statics.json
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/linglong/container/config.d)

# linglong default configuration
install(FILES ${CMAKE_CURRENT_LIST_DIR}/share/linglong/config.yaml
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/linglong)

# builder templates
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/share/linglong/builder/templates/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/linglong/builder/templates)

# systemd
set(SYSTEMD_SYSTEM_PRESET_PATH
    ${CMAKE_INSTALL_PREFIX}/lib/systemd/system-preset)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/systemd/system-preset/
        DESTINATION ${SYSTEMD_SYSTEM_PRESET_PATH})

set(SYSTEMD_SYSTEM_UNIT_PATH ${CMAKE_INSTALL_PREFIX}/lib/systemd)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/systemd/system
        DESTINATION ${SYSTEMD_SYSTEM_UNIT_PATH})

set(SYSTEMD_USER_UNIT_PATH ${CMAKE_INSTALL_PREFIX}/lib/systemd)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/systemd/user
        DESTINATION ${SYSTEMD_USER_UNIT_PATH})

set(SYSTEMD_SYSTEM_GENERATOR_PATH
    ${CMAKE_INSTALL_PREFIX}/lib/systemd/system-environment-generators)

install(
  PROGRAMS
    ${CMAKE_CURRENT_BINARY_DIR}/lib/systemd/system-environment-generators/61-linglong
  DESTINATION ${SYSTEMD_SYSTEM_GENERATOR_PATH})

# sysuser

set(SYSTEMD_SYSUSERSDIR ${CMAKE_INSTALL_PREFIX}/lib/sysusers.d)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/sysusers.d/
        DESTINATION ${SYSTEMD_SYSUSERSDIR})

# tmpfiles
set(SYSTEMD_TMPFILESDIR ${CMAKE_INSTALL_PREFIX}/lib/tmpfiles.d)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/tmpfiles.d/
        DESTINATION ${SYSTEMD_TMPFILESDIR})

# xdg
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/mime/packages
        DESTINATION ${CMAKE_INSTALL_DATADIR}/mime)

# set linglong XDG_DATA_DIRS environtment
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/script/linglong.sh
        DESTINATION /etc/profile.d)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/script/linglong.sh
  DESTINATION /etc/X11/Xsession.d/
  RENAME 21linglong)

# polkit actions this file only used to skip DBus security check, it will be
# removed later
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/share/polkit-1/actions/org.deepin.linglong.PackageManager.policy
  DESTINATION ${CMAKE_INSTALL_DATADIR}/polkit-1/actions)
