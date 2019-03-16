open Revery;
open Revery.UI;
open Revery.UI.Components;

open Types;

module Styles = {
  let container =
    Style.[
      flexDirection(`Row),
      /*      justifyContent(`JustifySpaceBetween),*/
      backgroundColor(Colors.darkOrange),
    ];
  let view = Style.[flexDirection(`Row)];
  let item =
    Style.[
      color(Colors.white),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(Themes.generalFontSize),
      margin(12),
    ];
};

let component = React.component("Hackernews_Header");

let make = (~setRoute, ()) =>
  component((hooks) =>
    (hooks, <View style=Styles.container>
      <View style=Styles.view>
        <Clickable onClick={() => setRoute(Top)}>
          <Text style=Styles.item text="HN" />
        </Clickable>
        <Clickable onClick={() => setRoute(Top)}>
          <Text style=Styles.item text="Top" />
        </Clickable>
        <Clickable onClick={() => setRoute(New)}>
          <Text style=Styles.item text="New" />
        </Clickable>
        <Clickable onClick={() => setRoute(Show)}>
          <Text style=Styles.item text="Show" />
        </Clickable>
        <Clickable onClick={() => setRoute(Ask)}>
          <Text style=Styles.item text="Ask" />
        </Clickable>
        <Clickable onClick={_ => setRoute(Jobs)}>
          <Text style=Styles.item text="Jobs" />
        </Clickable>
      </View>
      <View>
        <Text style=Styles.item text="Built with ReasonML and Revery" />
      </View>
    </View>)
  );

let createElement = (~children as _, ~setRoute, ()) =>
  make(~setRoute, ());
