/*
 * Fetch.re
 * 
 * Implementation of fetch API
 */

open Cohttp;
open Cohttp_lwt_unix;

module Cohttp_Response = Response;

let defaultOpts = Options.create();

module Response {
    type t = {
        status: int,
        text: unit => Lwt.t(string),
    };
}

let fetch = (~_opts=defaultOpts, url: string) => {
    Lwt.bind(Client.get(Uri.of_string(url)), ( ((resp, body)) => {
        let status = resp |> Cohttp_Response.status |> Code.code_of_status;

        let readText = (body, ()) => Cohttp_lwt.Body.to_string(body);

        Lwt.return(Response.({
            status,
            text: readText(body),
        }));
    }));
};
