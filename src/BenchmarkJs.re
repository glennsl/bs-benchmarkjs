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

type eventType =  [
  | `abort
  | `complete
  | `cycle
  | `error
  | `reset
  | `start
  | `unknown
];

let decodeEventType: string => eventType = fun
  | "abort" => `abort
  | "complete" => `complete
  | "cycle" => `cycle
  | "error" => `error
  | "reset" => `reset
  | "start" => `start
  | _ => `unknown;

let encodeEventType: eventType => string = fun
  | `abort => "abort"
  | `complete => "complete"
  | `cycle => "cycle"
  | `error => "error"
  | `reset => "reset"
  | `start => "start"
  | `unknown => "";

include BenchmarkJs__API.Impl({
  type nonrec benchmark = benchmark;
  type nonrec suite = suite;
  type nonrec suiteOptions = suiteOptions;
  type nonrec deferred = deferred;
  type nonrec event = event;
  type nonrec options = options;
  type nonrec times = times;
  type nonrec stats = stats;
  type nonrec platform = platform;
  type nonrec support = support;
  type nonrec testFn = testFn;
  type nonrec setupFn = setupFn;
  type nonrec teardownFn = teardownFn;
  type nonrec eventHandler = eventHandler;
  type nonrec eventType = eventType;
  let encodeEventType = encodeEventType;
  let decodeEventType = decodeEventType;
});
