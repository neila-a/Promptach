#include <QCoreApplication>
#include <promptachcommandlineparser.h>
#include <write.h>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);

    QTextStream stream(stdout);
    write(&stream);
}