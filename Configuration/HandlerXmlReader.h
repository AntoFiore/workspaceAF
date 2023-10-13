#ifndef HANDLERXMLREADER_H
#define HANDLERXMLREADER_H

#include <QXmlDefaultHandler>
namespace config{
class HandlerXmlReader : public QXmlDefaultHandler
{
public:
    HandlerXmlReader();
    bool startElement( const QString &namespaceURI,
    const QString &localName,
    const QString &qName,
    const QXmlAttributes &atts );
    bool endElement( const QString &namespaceURI,
    const QString &localName,
    const QString &qName );
    bool characters( const QString &ch );
    QString m_familyName;
    QString m_program;
    QString m_nationalSystem;
private:
    void handleCmd_T_IO(const QXmlAttributes &atts);
    void handleCmd_T_SIM(const QXmlAttributes &atts);
    void handleSetSubSet(const QXmlAttributes &atts);
    void handle_T_APDM(const QXmlAttributes &atts);
    void handle_T_APDM(const QXmlAttributes &atts, QString program);
    void handle_T_SingleCommand(const QXmlAttributes &atts, QString nationalSystem);

   // void handle_MT_APDM(const QXmlAttributes &atts);
    void handle_T_ODO(const QXmlAttributes &atts);
    void handle_T_RADIO_HOLE(const QXmlAttributes &atts);

     void handle_ConfigurationFile(const QString& tagName,const QXmlAttributes &atts);


};


}
#endif // HANDLERXMLREADER_H
