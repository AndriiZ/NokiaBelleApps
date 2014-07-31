/*
    Copyright (C) 2012 Dickson Leong
    This file is part of Tweetian.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 1.1
import com.nokia.symbian 1.1

QtObject {
    id: constant

    // color
    property color colorHighlighted: settings.invertedTheme ? platformStyle.colorHighlightedInverted
                                                            : platformStyle.colorHighlighted
    property color colorLight: settings.invertedTheme ? platformStyle.colorNormalLightInverted
                                                      : platformStyle.colorNormalLight
    property color colorMid: settings.invertedTheme ? platformStyle.colorNormalMidInverted
                                                    : platformStyle.colorNormalMid
    property color colorTextSelection: settings.invertedTheme ? platformStyle.colorTextSelection
                                                              : platformStyle.colorTextSelectionInverted
    property color colorMarginLine: settings.invertedTheme ? platformStyle.colorDisabledLightInverted
                                                           : platformStyle.colorDisabledMid

    // padding size
    property int paddingSmall: platformStyle.paddingSmall
    property int paddingMedium: platformStyle.paddingMedium
    property int paddingLarge: platformStyle.paddingLarge
    property int paddingXLarge: platformStyle.paddingLarge + platformStyle.paddingSmall

    // font size
    property int fontSizeXSmall: platformStyle.fontSizeSmall - 2
    property int fontSizeSmall: platformStyle.fontSizeSmall
    property int fontSizeMedium: platformStyle.fontSizeMedium
    property int fontSizeLarge: platformStyle.fontSizeLarge
    property int fontSizeXLarge: platformStyle.fontSizeLarge + 2
    property int fontSizeXXLarge: platformStyle.fontSizeLarge + 6

    // graphic size
    property int graphicSizeTiny: platformStyle.graphicSizeTiny
    property int graphicSizeSmall: platformStyle.graphicSizeSmall
    property int graphicSizeMedium: platformStyle.graphicSizeMedium
    property int graphicSizeLarge: platformStyle.graphicSizeLarge

    property int thumbnailSize: platformStyle.graphicSizeLarge * 1.5

    // other
    property int headerHeight: inPortrait ? 50 : 45

    property int charReservedPerMedia: 23

    property string userAgent: QMLUtils.userAgent()

}
