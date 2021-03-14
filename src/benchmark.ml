type nonrec suite

external makeSuite : string -> suite = "Suite" [@@new] [@@module "benchmark"]
external add : string -> (unit -> unit) -> suite = "add" [@@bs.send.pipe: suite]
external on : string -> (< .. >  Js.t -> unit) -> suite = "on" [@@bs.send.pipe: suite]
external run : unit -> unit = "run" [@@bs.send.pipe: suite]
