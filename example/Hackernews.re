open Revery;
open Revery.UI;

open Types;

module Hackernews = {
  let component = React.component("Hackernews_Hackernews");

  let make = () =>
    component(hooks => {
      let (route, setRoute, hooks) =
        React.Hooks.state(Top, hooks);
      (hooks, <View>
        <Header setRoute />
        {switch (route) {
         | Comments(_id) => <View />
         | Profile(_user) => <View />
         | _ => <Listing route />
         }}
      </View>);
      /*
       <Router
         defaultRoute=Top
         view={(~route: route, ~setRoute: route => unit) =>
           <View>
             <Header setRoute />
             {switch (route) {
              | Comments(_id) => <View />
              | Profile(_user) => <View />
              | _ => <Listing route />
              }}
           </View>
         }
       />;*/
    });

  let createElement = (~children as _, ()) => make();
};

let init = app => {
  let win =
    App.createWindow(
      app,
      "ReHackernews",
      ~createOptions={
        ...Window.defaultCreateOptions,
        backgroundColor: Themes.currentTheme.contents.overallBackgroundColor,
      },
    );

  UI.start(win, () => <Hackernews />);
};

App.start(init);
