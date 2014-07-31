import QtQuick 1.1
import com.nokia.symbian 1.1
import "Component"
import "Page"
import ProviderModel 1.0

PageStackWindow {
    id: window
    initialPage: MainPage {id: mainPage}
    showStatusBar: true

    property variant addProviderPage: AddProviderPage {}
    property variant viewProviderPage: ViewProviderPage {}

    ToolTip {
        id: toolTip
        visible: false
    }

    Settings { id: settings }
    Constant { id: constant }
    ProviderModel {
        id: providerModel
    }
}
