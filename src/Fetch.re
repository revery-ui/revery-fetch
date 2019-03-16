/*
 * Fetch.re
 * 
 * Implementation of fetch API
 */

let defaultOpts = Options.create();

let fetch = (~opts=defaultOpts, url: string) => {
    print_endline ("Hello, world: " ++ url);
};
