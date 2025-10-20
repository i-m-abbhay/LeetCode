function TimeLimitedCache() {
  // key -> { value, expiresAt, timer }
  this.store = new Map();
}

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  const now = Date.now();
  const existing = this.store.get(key);
  const wasUnexpired = !!(existing && existing.expiresAt > now);

  if (existing && existing.timer) clearTimeout(existing.timer);

  const expiresAt = now + duration;
  const timer = setTimeout(() => {
    const cur = this.store.get(key);
    if (cur && cur.expiresAt <= Date.now()) {
      this.store.delete(key);
    }
  }, duration);

  this.store.set(key, { value, expiresAt, timer });
  return wasUnexpired; // boolean per spec
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  const entry = this.store.get(key);
  if (!entry) return -1;

  if (entry.expiresAt <= Date.now()) {
    clearTimeout(entry.timer);
    this.store.delete(key);
    return -1;
  }
  return entry.value;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  const now = Date.now();
  let cnt = 0;
  for (const [k, entry] of this.store) {
    if (entry.expiresAt > now) {
      cnt++;
    } else {
      clearTimeout(entry.timer);
      this.store.delete(k);
    }
  }
  return cnt;
};
