type user = {id: int};

/* Router types should probably be with Router in the future. */
type route =
  | Top
  | New
  | Show
  | Ask
  | Jobs
  | Comments(int)
  | Profile(user);

type post = {
  title: string,
  url: option(string),
  author: string,
  votes: int,
  time: int,
  numberOfComments: option(int),
};