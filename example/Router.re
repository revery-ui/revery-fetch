open Revery.UI;

open Types;

/*
   `Router` is a simple component that re-renders if the route changes.
   It does not handle history.
 */
let component = React.component("Hackernews_Router");

let make = (~defaultRoute, ~view, ()) =>
  component(slots => {
    let (route, setRoute, _slots: React.Hooks.empty) =
      React.Hooks.state(defaultRoute, slots);
    <View> {view(~route, ~setRoute)} </View>;
  });
/*
 let (route, setRoute, _slots: React.Hooks.empty) = React.Hooks.state(defaultRoute, slots);
 ~view(~route, ~setRoute);
 */

let createElement = (~children as _, ~defaultRoute: route, ~view, ()) =>
  React.element(make(~defaultRoute, ~view, ()));