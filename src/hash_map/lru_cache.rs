use std::collections::HashMap;

struct LruCache {
    capacity: usize,
    map: HashMap<i32, i32>,
    order: Vec<i32>,
}

impl LruCache {
    fn new(capacity: i32) -> Self {
        LruCache {
            capacity: capacity as usize,
            map: HashMap::new(),
            order: Vec::new(),
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if let Some(&value) = self.map.get(&key) {
            Self::touch(&mut self.order, key);
            return value;
        }
        -1
    }

    fn put(&mut self, key: i32, value: i32) {
        if let std::collections::hash_map::Entry::Occupied(mut e) = self.map.entry(key) {
            e.insert(value);
            Self::touch(&mut self.order, key);
            return;
        }

        if self.map.len() == self.capacity
            && let Some(old_key) = self.order.first().cloned()
        {
            self.order.remove(0);
            self.map.remove(&old_key);
        }

        self.map.insert(key, value);
        self.order.push(key);
    }

    fn touch(order: &mut Vec<i32>, key: i32) {
        if let Some(pos) = order.iter().position(|&k| k == key) {
            order.remove(pos);
        }
        order.push(key);
    }
}

#[cfg(test)]
mod tests {
    use super::LruCache;
    use rstest::rstest;

    #[rstest]
    fn test_lru_cache() {
        let mut cache = LruCache::new(2);
        cache.put(1, 1);
        cache.put(2, 2);
        assert_eq!(cache.get(1), 1);
        cache.put(3, 3);
        assert_eq!(cache.get(2), -1);
        cache.put(4, 4);
        assert_eq!(cache.get(1), -1);
        assert_eq!(cache.get(3), 3);
        assert_eq!(cache.get(4), 4);
    }
}
