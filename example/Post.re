open Revery;
open Revery.UI;

open Types;

module Styles = {
  let view =
    Style.[
      flexDirection(`Row),
      backgroundColor(Themes.currentTheme.contents.postBackgroundColor),
      marginBottom(1),
    ];
  let numberOfVotes =
    Style.[
      color(Colors.darkOrange),
      fontFamily("Roboto-Bold.ttf"),
      fontSize(Themes.generalFontSize),
      margin(20),
    ];
  let contentContainer = Style.[margin(10)];
  let content =
    Style.[
      backgroundColor(Themes.currentTheme.contents.postBackgroundColor),
      color(Themes.currentTheme.contents.postTextColor),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(Themes.generalFontSize),
    ];
  let contentTitleContainer = Style.[flexDirection(`Row)];
  let contentTitleURL =
    Style.[
      backgroundColor(Themes.currentTheme.contents.postBackgroundColor),
      color(Colors.lightSlateGray),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(Themes.generalFontSize),
    ];
  let subcontent =
    Style.[
      color(Colors.lightSlateGray),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(Themes.generalFontSize),
    ];
};

let component = React.component("Hackernews_Post");

let make = (~post: post, ()) =>
  component((hooks) => {
    let subcontentText =
      "by "
      ++ post.author
      ++ " some time ago"
      ++ (
        switch (post.numberOfComments) {
        | None => ""
        | Some(count) => " | " ++ string_of_int(count) ++ " comments"
        }
      );

    let url =
      switch (post.url) {
      | Some(url) => " (" ++ url ++ ")"
      | None => ""
      };

    (hooks, <View style=Styles.view>
      <Text style=Styles.numberOfVotes text={string_of_int(post.votes)} />
      <View style=Styles.contentContainer>
        <View style=Styles.contentTitleContainer>
          <Text style=Styles.content text={post.title} />
          <Text style=Styles.contentTitleURL text=url />
        </View>
        <Text style=Styles.subcontent text=subcontentText />
      </View>
    </View>);
  });

let createElement = (~children as _, ~post: post, ()) =>
  make(~post, ());
