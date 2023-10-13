#include "HandlerPaclage_3_4_0_Factory.h"

#include "HandlerPackage_0_Ver340.h"
#include "HandlerPackage_2_Ver340.h"
#include "HandlerPackage_3_Ver340.h"
#include "HandlerPackage_5_Ver340.h"
#include "HandlerPackage_6_Ver340.h"
#include "HandlerPackage_12_Ver340.h"
#include "HandlerPackage_13_Ver340.h"
#include "HandlerPackage_15_Ver340.h"
#include "HandlerPackage_16_Ver340.h"
#include "HandlerPackage_21_Ver340.h"
#include "HandlerPackage_27_Ver340.h"
#include "HandlerPackage_40_Ver340.h"
#include "HandlerPackage_41_Ver340.h"
#include "HandlerPackage_42_Ver340.h"
#include "HandlerPackage_45_Ver340.h"
#include "HandlerPackage_44_Ver340.h"
#include "HandlerPackage_46_Ver340.h"
#include "HandlerPackage_49_Ver340.h"
#include "HandlerPackage_51_Ver340.h"
#include "HandlerPackage_52_Ver340.h"
#include "HandlerPackage_57_Ver340.h"
#include "HandlerPackage_58_Ver340.h"
#include "HandlerPackage_63_Ver340.h"
#include "HandlerPackage_39_Ver340.h"
#include "HandlerPackage_64_Ver340.h"
#include "HandlerPackage_65_Ver340.h"
#include "HandlerPackage_66_Ver340.h"
#include "HandlerPackage_67_Ver340.h"
#include "HandlerPackage_68_Ver340.h"
#include "HandlerPackage_69_Ver340.h"
#include "HandlerPackage_70_Ver340.h"
#include "HandlerPackage_71_Ver340.h"
#include "HandlerPackage_72_Ver340.h"
#include "HandlerPackage_76_Ver340.h"
#include "HandlerPackage_79_Ver340.h"
#include "HandlerPackage_80_Ver340.h"
#include "HandlerPackage_88_Ver340.h"
#include "HandlerPackage_90_Ver340.h"
#include "HandlerPackage_131_Ver340.h"
#include "HandlerPackage_132_Ver340.h"
#include "HandlerPackage_133_Ver340.h"
#include "HandlerPackage_134_Ver340.h"
#include "HandlerPackage_135_Ver340.h"
#include "HandlerPackage_136_Ver340.h"
#include "HandlerPackage_137_Ver340.h"
#include "HandlerPackage_138_Ver340.h"
#include "HandlerPackage_139_Ver340.h"
#include "HandlerPackage_140_Ver340.h"
#include "HandlerPackage_141_Ver340.h"
#include "HandlerPackage_143_Ver340.h"
#include "HandlerPackage_145_Ver340.h"
#include "HandlerPackage_180_Ver340.h"
#include "HandlerPackage_181_Ver340.h"
#include "HandlerPackage_254_Ver340.h"


namespace package{
HandlerPaclage_3_4_0_Factory::HandlerPaclage_3_4_0_Factory(QObject *parent)
    : QObject{parent}
{

}

HandlerPackage *HandlerPaclage_3_4_0_Factory::createHandlerPackage(qint16 idPkg)
{

    HandlerPackage *handlerPkg=nullptr;
    switch (idPkg) {
    case 0:
        handlerPkg= new HandlerPackage_0_Ver340;
        break;
    case 2:
        handlerPkg= new HandlerPackage_2_Ver340;
        break;
    case 3:
        handlerPkg= new HandlerPackage_3_Ver340;
        break;
    case 5:
        handlerPkg= new HandlerPackage_5_Ver340;
        break;
    case 6:
        handlerPkg= new HandlerPackage_6_Ver340;
        break;
    case 12:
        handlerPkg = new HandlerPackage_12_Ver340;
        break;
    case 13:
        handlerPkg = new HandlerPackage_13_Ver340;
        break;
    case 15:
        handlerPkg = new HandlerPackage_15_Ver340;
        break;
    case 16:
        handlerPkg = new HandlerPackage_16_Ver340;
        break;
    case 21:
        handlerPkg = new HandlerPackage_21_Ver340;
        break;
    case 27:
        handlerPkg = new HandlerPackage_27_Ver340;
        break;
    case 39:
        handlerPkg = new HandlerPackage_39_Ver340;
        break;
    case 40:
        handlerPkg = new HandlerPackage_40_Ver340;
        break;
    case 41:
        handlerPkg = new HandlerPackage_41_Ver340;
        break;
    case 42:
        handlerPkg = new HandlerPackage_42_Ver340;
        break;
    case 44:
        handlerPkg = new HandlerPackage_44_Ver340;
        break;
    case 45:
        handlerPkg = new HandlerPackage_45_Ver340;
        break;
    case 46:
        handlerPkg = new HandlerPackage_46_Ver340;
        break;
    case 49:
        handlerPkg = new HandlerPackage_49_Ver340;
        break;
    case 51:
        handlerPkg = new HandlerPackage_51_Ver340;
        break;
    case 52:
        handlerPkg = new HandlerPackage_52_Ver340;
        break;
    case 57:
        handlerPkg = new HandlerPackage_57_Ver340;
        break;
    case 58:
        handlerPkg = new HandlerPackage_58_Ver340;
        break;
    case 63:
        handlerPkg = new HandlerPackage_63_Ver340;
        break;
    case 64:
        handlerPkg = new HandlerPackage_64_Ver340;
        break;
    case 65:
        handlerPkg = new HandlerPackage_65_Ver340;
        break;
    case 66:
        handlerPkg = new HandlerPackage_66_Ver340;
        break;
    case 67:
        handlerPkg = new HandlerPackage_67_Ver340;
        break;
    case 68:
        handlerPkg = new HandlerPackage_68_Ver340;
        break;
    case 69:
        handlerPkg = new HandlerPackage_69_Ver340;
        break;
    case 70:
        handlerPkg = new HandlerPackage_70_Ver340;
        break;
    case 71:
        handlerPkg = new HandlerPackage_71_Ver340;
        break;
    case 72:
        handlerPkg = new HandlerPackage_72_Ver340;
        break;
    case 76:
        handlerPkg = new HandlerPackage_76_Ver340;
        break;
    case 79:
        handlerPkg = new HandlerPackage_79_Ver340;
        break;
    case 80:
        handlerPkg = new HandlerPackage_80_Ver340;
        break;
    case 88:
        handlerPkg = new HandlerPackage_88_Ver340;
        break;
    case 90:
        handlerPkg = new HandlerPackage_90_Ver340;
        break;
    case 131:
        handlerPkg = new HandlerPackage_131_Ver340;
        break;
    case 132:
        handlerPkg = new HandlerPackage_132_Ver340;
        break;
    case 133:
        handlerPkg = new HandlerPackage_133_Ver340;
        break;
    case 134:
        handlerPkg = new HandlerPackage_134_Ver340;
        break;
    case 135:
        handlerPkg = new HandlerPackage_135_Ver340;
        break;
    case 136:
        handlerPkg = new HandlerPackage_136_Ver340;
        break;
    case 137:
        handlerPkg = new HandlerPackage_137_Ver340;
        break;
    case 138:
        handlerPkg = new HandlerPackage_138_Ver340;
        break;
    case 139:
        handlerPkg = new HandlerPackage_139_Ver340;
        break;
    case 140:
        handlerPkg = new HandlerPackage_140_Ver340;
        break;
    case 141:
        handlerPkg = new HandlerPackage_141_Ver340;
        break;
    case 143:
        handlerPkg = new HandlerPackage_143_Ver340;
        break;
    case 145:
        handlerPkg = new HandlerPackage_145_Ver340;
        break;
    case 180:
        handlerPkg = new HandlerPackage_180_Ver340;
        break;
    case 181:
        handlerPkg = new HandlerPackage_181_Ver340;
        break;
    case 254:
        handlerPkg = new HandlerPackage_254_Ver340;
        break;

    default:

        break;
    }
    return handlerPkg;

}
}
