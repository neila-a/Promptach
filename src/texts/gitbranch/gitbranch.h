#ifndef GITBRANCH_H
#define GITBRANCH_H

#include <texts.h>
#include <textinterface.h>
#include <utils.h>

class GitBranch : public QObject, public TextInterface {
    Q_OBJECT;
    Q_INTERFACES(TextInterface);
    Q_PLUGIN_METADATA(IID TextInterface_iid);

public:
    coloredText getText() {
        const bool isGit = isInGit();
        QString branch = isGit ? run("git", { "branch", "--show-current" }).trimmed() : "";
        return { branch, GITBRANCH };
    }
};

#endif