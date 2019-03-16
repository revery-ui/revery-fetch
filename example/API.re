open Lwt.Infix;
/* open Cohttp_lwt_unix; */

open Revery_fetch.Fetch;
open Revery_fetch.Fetch.Response;

let baseURL = "https://hacker-news.firebaseio.com/v0";
let top = baseURL ++ "/topstories.json";
let new_ = baseURL ++ "/newstories.json";
let show = baseURL ++ "/showstories.json";
let ask = baseURL ++ "/askstories.json";
let jobs = baseURL ++ "/jobstories.json";

let item = (id: int) => baseURL ++ "/item/" ++ string_of_int(id) ++ ".json";

let urlFromRoute = route =>
  Types.(
    switch (route) {
    | Top => top
    | New => new_
    | Show => show
    | Ask => ask
    | Jobs => jobs
    | _ => top
    }
  );

let toString = (resp) => resp.text();

let fetchItemIds = url => fetch(url) >>= toString;
let fetchItemIdsFromRoute = route => route |> urlFromRoute |> fetchItemIds;
let fetchItem = id => fetch(item(id)) >>= toString;
