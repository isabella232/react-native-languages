/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#ifndef RNLANGUAGESDESKTOP_H
#define RNLANGUAGESDESKTOP_H

#include <QUrl>

#include "moduleinterface.h"

class RNLanguagesPrivate;
class RNLanguages : public QObject, public ModuleInterface {
    Q_OBJECT

    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(RNLanguages)

public:
    Q_INVOKABLE RNLanguages(QObject* parent = 0);
    ~RNLanguages();

    Q_INVOKABLE REACT_PROMISE void getLanguages(double successCallback, double errorCallback);
    virtual QString moduleName() override;
    virtual QList<ModuleMethod*> methodsToExport() override;
    virtual QVariantMap constantsToExport() override;
    virtual void setBridge(Bridge* bridge) override;

private:
    QScopedPointer<RNLanguagesPrivate> d_ptr;
};

#endif // RNLANGUAGESDESKTOP_H

