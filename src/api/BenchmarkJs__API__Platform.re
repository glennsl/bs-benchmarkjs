/**
 * [ Platform ]
 *
 * Contains functions for getting information about the host environment,
 * including the browser/runtime, operating system, physical device model,
 * device manufacturer, etc.
 */
module Impl = (T: {type t;}) => {
  module Internal =
    BenchmarkJs__FFI.Platform.Impl({
      type t = T.t;
    });
  /** A short string describing the host operating system and runtime platform. */
  let description: string = Internal.(getDescription(data));
  /** The host platform's JS interpreter engine. E.g. "WebKit", "V8", "SpiderMonkey". */
  let layout: string = Internal.(getLayout(data));
  /** The host device name. E.g. "iPad", "Android Galaxy S3". */
  let product: string = Internal.(getProduct(data));
  /** The name of the host platfrom or browser. E.g. "Safari", "Node", "Firefox". */
  let name: string = Internal.(getName(data));
  /** The name of the device manufacturer. E.g. "HP", "Apple", "Microsoft". */
  let manufacturer: string = Internal.(getManufacturer(data));
  /** The name of the host operating system. E.g. "Ubuntu 18.04". */
  let os: string = Internal.(getOS(data));
  /** */
  let prerelease: string = Internal.(getPrerelease(data));
  /** */
  let version: string = Internal.(getVersion(data));
  /** Returns the [ description ] property (string) or an empty string if the description is not available. */
  let toString: unit => string = () => Internal.(toString(data));
};