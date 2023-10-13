QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


CONFIG *= debug_and_release debug_and_release_target
debug_and_release_target  {
    CONFIG(debug, debug|release) {
        BUILD_CONFIG += "debug"
    } else {
        BUILD_CONFIG += "release"
    }
    message("Def target : " + $$BUILD_CONFIG)
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Configuration
INCLUDEPATH += $$PWD/Controller
INCLUDEPATH += $$PWD/DataCommands
INCLUDEPATH += $$PWD/Ui
INCLUDEPATH += $$PWD/Common
INCLUDEPATH += $$PWD/GraphicStepSequence
#INCLUDEPATH += $$PWD/GraphicHandlerCommands
INCLUDEPATH += $$PWD/Pages/
INCLUDEPATH += $$PWD/Pages/Scenario
INCLUDEPATH += $$PWD/Pages/Scenario/Generate
INCLUDEPATH += $$PWD/Pages/Settings
INCLUDEPATH += $$PWD/Export
INCLUDEPATH += $$PWD/Package
INCLUDEPATH += $$PWD/Package/Pkg_3_6_0
INCLUDEPATH += $$PWD/Package/Pkg_3_4_0




SOURCES += \
    Configuration/HandlerXmlReader.cpp \
    Configuration/ReadWriteConfigurationFile.cpp \
    Controller/Controller.cpp \
    DataCommands/MngStorageOutCommand.cpp \
    DataCommands/StorageDataCommand.cpp \
    DataCommands/StorageOutDataBaliseCommand.cpp \
    Export/ExportCsv.cpp \
    Export/ExportData.cpp \
   # Package/FormPackage_0.cpp \
    #Package/FormPackage_1.cpp \
    Package/GraphicBtnPackage.cpp \
    Package/GraphicBtnPackage_BL_3_2_0.cpp \
    Package/GraphicBtnPackage_BL_3_4_0.cpp \
    Package/GraphicBtnPackage_BL_3_6_0.cpp \
    Package/GraphicTitlePkg.cpp \
    Package/GraphicVariablePkg.cpp \
    Package/HandlerPackage.cpp \
    Package/HandlerPaclage_3_4_0_Factory.cpp \
    Package/HandlerPaclage_3_6_0_Factory.cpp \
   # Package/PackegeSerive.cpp \
    Package/Pkg_3_4_0/HandlerPackage_0_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_12_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_131_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_132_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_133_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_134_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_135_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_136_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_137_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_138_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_139_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_13_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_140_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_141_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_143_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_145_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_15_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_16_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_180_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_181_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_21_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_254_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_27_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_2_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_39_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_3_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_40_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_41_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_42_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_44_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_45_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_46_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_49_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_51_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_52_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_57_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_58_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_5_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_63_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_64_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_65_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_66_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_67_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_68_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_69_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_6_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_70_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_71_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_72_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_76_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_79_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_80_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_88_Ver340.cpp \
    Package/Pkg_3_4_0/HandlerPackage_90_Ver340.cpp \
    Package/Pkg_3_6_0/HandlerPackage_0_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_2_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_3_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_5_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_6_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_12_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_13_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_15_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_16_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_21_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_27_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_39_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_40_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_41_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_42_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_44_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_45_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_46_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_49_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_51_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_52_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_57_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_58_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_63_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_64_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_65_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_66_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_67_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_68_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_69_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_70_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_71_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_72_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_76_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_79_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_80_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_88_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_90_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_131_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_132_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_133_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_134_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_135_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_136_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_137_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_138_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_139_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_140_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_141_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_143_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_145_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_180_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_181_Ver360.cpp \
    Package/Pkg_3_6_0/HandlerPackage_254_Ver360.cpp \
    Pages/GraphicHandlerPage.cpp \
   # Pages/Scenario/Generate/GraphicEditBalise.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_BALISE.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_MT_APDM.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_SINGLE.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_APDM.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_IO.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand.cpp \
    GraphicStepSequence/GraphicStepSequence.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_ODO.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_RADIO_HOLE.cpp \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_SIM.cpp \
    Pages/Scenario/Generate/GraphicHandlerCreateScenario.cpp \
    Pages/Scenario/Generate/GraphicHandlerHeaderCommand_BALISE.cpp \
    Pages/Scenario/Generate/GraphicHandlerTreeBalise.cpp \
    Pages/Settings/GraphicHandlerSettings.cpp \
    Pages/Scenario/Generate/ServiceCommand.cpp \
  #  Ui/GraphicViewPackage.cpp \
    Ui/mainwindow.cpp \
    main.cpp \
   

HEADERS += \
    Common/Define.h \
    Configuration/Data_Configuration.h \
    Configuration/Defxml.h \
    Configuration/HandlerXmlReader.h \
    Configuration/ReadWriteConfigurationFile.h \
    Controller/Controller.h \
    DataCommands/DataMT_APDM_Command.h \
    DataCommands/DataSingle_Command..h \
    DataCommands/DataSubSet.h \
    DataCommands/DataT_APDM_Command.h \
    DataCommands/DataT_IO_Command.h \
    DataCommands/DataT_ODO_Command.h \
    DataCommands/DataT_RADIO_HOLE_Command.h \
    DataCommands/DataT_SIM_Command.h \
    DataCommands/MngStorageOutCommand.h \
    DataCommands/OutDataBalise_Command.h \
    DataCommands/StorageDataCommand.h \
    DataCommands/StorageOutDataBaliseCommand.h \
    Export/ExportCsv.h \
    Export/ExportData.h \
    #Package/FormPackage_0.h \
    #Package/FormPackage_1.h \
    Package/GraphicBtnPackage.h \
    Package/GraphicBtnPackage_BL_3_2_0.h \
    Package/GraphicBtnPackage_BL_3_4_0.h \
    Package/GraphicBtnPackage_BL_3_6_0.h \
    Package/GraphicTitlePkg.h \
    Package/GraphicVariablePkg.h \
    Package/HandlerPackage.h \
    Package/HandlerPaclage_3_4_0_Factory.h \
    Package/HandlerPaclage_3_6_0_Factory.h \
   # Package/PackegeSerive.h \
    Package/Pkg_3_4_0/HandlerPackage_0_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_12_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_131_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_132_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_133_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_134_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_135_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_136_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_137_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_138_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_139_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_13_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_140_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_141_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_143_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_145_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_15_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_16_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_180_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_181_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_21_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_254_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_27_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_2_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_39_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_3_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_40_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_41_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_42_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_44_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_45_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_46_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_49_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_51_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_52_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_57_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_58_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_5_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_63_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_64_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_65_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_66_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_67_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_68_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_69_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_6_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_70_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_71_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_72_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_76_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_79_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_80_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_88_Ver340.h \
    Package/Pkg_3_4_0/HandlerPackage_90_Ver340.h \
    Package/Pkg_3_6_0/HandlerPackage_0_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_2_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_3_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_5_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_6_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_15_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_66_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_12_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_13_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_16_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_21_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_27_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_39_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_40_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_41_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_49_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_42_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_44_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_45_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_46_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_51_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_52_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_57_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_58_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_63_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_64_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_65_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_67_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_68_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_69_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_70_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_71_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_72_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_76_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_79_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_80_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_88_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_90_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_131_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_132_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_133_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_134_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_135_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_136_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_137_Ver360.h\
    Package/Pkg_3_6_0/HandlerPackage_138_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_139_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_140_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_141_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_143_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_145_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_180_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_181_Ver360.h \
    Package/Pkg_3_6_0/HandlerPackage_254_Ver360.h \
    Pages/GraphicHandlerPage.h \
  # Pages/Scenario/Generate/GraphicEditBalise.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_BALISE.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_MT_APDM.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_SINGLE.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_APDM.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_IO.h \
    Pages/Scenario/Generate/GraphicHandlerCommand.h \
    GraphicStepSequence/GraphicStepSequence.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_ODO.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_RADIO_HOLE.h \
    Pages/Scenario/Generate/GraphicHandlerCommand_T_SIM.h \
    Pages/Scenario/Generate/GraphicHandlerCreateScenario.h \
    Pages/Scenario/Generate/GraphicHandlerHeaderCommand_BALISE.h \
    Pages/Scenario/Generate/GraphicHandlerTreeBalise.h \
    Pages/Scenario/Generate/ServiceCommand.h \
    Pages/Settings/GraphicHandlerSettings.h \
  #  Ui/GraphicViewPackage.h \
    Ui/mainwindow.h

FORMS += \
   # Pages/Scenario/Generate/GraphicViewPackage.ui \
  #  Package/FormPackage_0.ui \
  #  Package/formpackage_1.ui \
  #  Ui/GraphicViewPackage.ui \
    Ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += file_copies
COPIES += ConfigurationFile
ConfigurationFile.files += $$files($$PWD/Config.xml)
ConfigurationFile.path = $$OUT_PWD/$$BUILD_CONFIG
#ConfigurationFile.path = $$OUT_PWD/

COPIES += ConfigurationFileEtc
ConfigurationFileEtc.files += $$files($$PWD/etc/*)
ConfigurationFileEtc.path = $$OUT_PWD/$$BUILD_CONFIG/etc/


DISTFILES += \
    etc/t_io_config_scenario_creator.xml

RESOURCES += \
    resource/resource.qrc
