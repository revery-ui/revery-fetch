/*
 * Options.re
 * 
 * Implementation of fetch init options
 */

type method =
| Get
| Post;


type t = {
    method,
};

let create = (
    ~method=Get,
    (),
) => {
    method: method,
};
