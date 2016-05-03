class LRUCache{
public:
	//������δʹ�õķ���list���ң���back
	list<int> key_cache;
	unordered_map<int,int> m;
	unordered_map<int,list<int>::iterator> m_k2i;//key:list�еĵ�����
	int max_size;
	LRUCache(int capacity) {
		key_cache.clear();
		m.clear();
		max_size = capacity;
	}

	int get(int key) {
		if(m.find(key)==m.end())
			return -1;
		else
		{

			key_cache.erase(m_k2i[key]);
			key_cache.push_front(key);
			m_k2i[key] = key_cache.begin();
			return m[key];
		}
	}

	void set(int key, int value) {
		if(m.find(key)==m.end())
		{
			if(max_size==0)
			{
				m.erase(key_cache.back());
				m_k2i.erase(key_cache.back());
				key_cache.pop_back();
				++max_size;
			}
			key_cache.push_front(key);
			m[key] = value;
			m_k2i[key] = key_cache.begin();
			--max_size;
		}
		else
		{
			key_cache.erase(m_k2i[key]);
			key_cache.push_front(key);
			m[key] = value;
			m_k2i[key] = key_cache.begin();
		}
	}
};