
type benchmark;
type suite;
type suiteOptions;
type deferred;
type event;
type options;
type times;
type stats;
type platform;
type support;

type testFn = (. unit) => unit;
type setupFn = (. unit) => unit;
type teardownFn = (. unit) => unit;
type eventHandler = (. event) => unit;

type eventName =  [
  | `abort
  | `complete
  | `cycle
  | `error
  | `reset
  | `start
  | `unknown
];


let decodeEventName: string => eventName = fun
  | "abort" => `abort
  | "complete" => `complete
  | "cycle" => `cycle
  | "error" => `error
  | "reset" => `reset
  | "start" => `start
  | _ => `unknown;

let encodeEventName: eventName => string = fun
  | `abort => "abort"
  | `complete => "complete"
  | `cycle => "cycle"
  | `error => "error"
  | `reset => "reset"
  | `start => "start"
  | `unknown => ""
