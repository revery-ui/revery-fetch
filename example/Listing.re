open Revery.UI;

let component = React.component("Hackernews_Listing");

let make = (~route, ()) =>
  component((hooks) => {
    let posts =
      route
      |> API.fetchItemIdsFromRoute
      |> Lwt_main.run
      |> Decoder.postIds
      |> ListUtils.firstN(10)
      |> List.map(id => id |> API.fetchItem |> Lwt_main.run |> Decoder.post);

    let postsToElements = posts => posts |> List.map(post => <Post post />);

    (hooks,<View> ...{postsToElements(posts)} </View>);
  });

let createElement = (~children as _, ~route, ()) =>
  make(~route, ());
