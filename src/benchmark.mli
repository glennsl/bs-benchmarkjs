
type suite

external makeSuite : string -> suite = "Suite" [@@bs.new] [@@bs.module "benchmark"]
external add : string -> (unit -> unit) -> suite = "" [@@bs.send.pipe: suite]
external on : string -> (< .. > Js.t -> unit) -> suite = "" [@@bs.send.pipe: suite]
external run : unit -> unit = "" [@@bs.send.pipe: suite]
