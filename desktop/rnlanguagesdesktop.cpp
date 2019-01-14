/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include <memory>

#include "bridge.h"
#include "rnlanguagesdesktop.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QLocale>
#include <QMap>
#include <QNetworkDiskCache>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QQuickImageProvider>

namespace {
struct RegisterQMLMetaType {
    RegisterQMLMetaType() {
        qRegisterMetaType<RNLanguages*>();
    }
} registerMetaType;
} // namespace

class RNLanguagesPrivate {

public:
    RNLanguagesPrivate() {}

    Bridge* bridge = nullptr;

    QVariantList languages() {
        QStringList languages = QLocale().uiLanguages();
        QVariantList variantLanguages;
        for (QString l : languages) {
            variantLanguages.push_back(l);
        }
        return variantLanguages;
    }
};

RNLanguages::RNLanguages(QObject* parent) : QObject(parent), d_ptr(new RNLanguagesPrivate) {}

RNLanguages::~RNLanguages() {}

void RNLanguages::getLanguages(double successCallback, double errorCallback) {
    Q_D(RNLanguages);
    QVariantList args;
    args.push_back(d->languages());

    if (d->bridge) {
        d->bridge->invokePromiseCallback(successCallback, args);
    }
}

QString RNLanguages::moduleName() {
    return "RNLanguages";
}

QList<ModuleMethod*> RNLanguages::methodsToExport() {
    return QList<ModuleMethod*>{};
}

QVariantMap RNLanguages::constantsToExport() {
    return QVariantMap{{"languages", d_ptr->languages()}};
}

void RNLanguages::setBridge(Bridge* bridge) {
    Q_D(RNLanguages);
    d->bridge = bridge;
}

